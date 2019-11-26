using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using Android.App;
using Android.Content;
using Android.Content.PM;
using Android.OS;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Android.Support.V4.Content;
using Pxb.Android.Axml;

namespace ModCommon
{
    public class ModHelper
    {
        private const string MOD_TAG_FILE = "questhooker.modded";
        public const string LIBMODLOADER_TARGET_FILE = "lib/armeabi-v7a/libmodloader.so";
        public const string LIBMODLOADER_TARGET_FILE_64 = "lib/arm64-v8a/libmodloader.so";
        public event EventHandler<string> StatusUpdated;
        private Context _context;
        private string _tempApk;
        Action<string> _triggerUninstall;
        Action<string> _triggerInstall;
        private byte[] _modLoaderBytes;
        private byte[] _modLoaderBytes64;

        public string PackageName { get; private set; }
        public ModHelper(string packageName, Context context, byte[] modLoaderBytes, byte[] modLoaderBytes64, Action<string> triggerUninstall, Action<string> triggerInstall)
        {
            PackageName = packageName;
            _context = context;
            _triggerInstall = triggerInstall;
            _triggerUninstall = triggerUninstall;
            _modLoaderBytes = modLoaderBytes;
            _modLoaderBytes64 = modLoaderBytes64;
        }

        internal string TempApk
        {
            get
            {
                if (_tempApk == null)
                {
                    CheckCleanupTempApk();
                    TryFindTempApk();
                }
                return _tempApk;
            }
            private set
            {
                _tempApk = value;
            }
        }

        public bool DoesTempApkExist
        {
            get
            {
                return TempApk != null && File.Exists(TempApk);
            }
        }

        public bool IsTempApkModded
        {
            get
            {
                if (TempApk == null)
                {
                    Log.LogErr("IsTempApkModded was called, but the TempApk does not exist!");
                    throw new ModException("IsTempApkModded was called, but the TempApk does not exist!");
                }
                return CheckApkHasModTagFile(TempApk);
            }
        }

        public void CheckCleanupTempApk()
        {
            try
            {
                if (IsPackageInstalled && IsInstalledPackageModded)
                {
                    string filename = Path.Combine(_context.ExternalCacheDir.AbsolutePath, $"mod.{PackageName}.apk");
                    if (File.Exists(filename))
                    {
                        File.Delete(filename);
                    }
                }
            }
            catch (Exception ex)
            {
                Log.LogErr("Exception trying to clean up the temp APK", ex);
            }
        }

        public bool IsInstalledPackageModded
        {
            get
            {
                string bsApk = FindPackageApk();
                if (bsApk == null)
                {
                    Log.LogErr($"Tried to call {nameof(IsInstalledPackageModded)} when {PackageName} isn't installed.");
                    throw new ModException($"{PackageName} is not installed, cannot check if it is modded.");
                }
                try
                {
                    return CheckApkHasModTagFile(bsApk);
                }
                catch (Exception ex)
                {
                    Log.LogErr($"Exception in {nameof(IsInstalledPackageModded)} when trying to check if it is modded.", ex);
                    throw new ModException($"Error checking if installed {PackageName} is modded.", ex);
                }
            }
        }

        public bool IsPackageInstalled
        {
            get
            {
#if EMULATOR
                return true;
#endif
                return FindPackageApk() != null;
            }
        }

        public bool CheckIsTempApkReadyForInstall()
        {
            try
            {
                if (TempApk == null)
                    return false;
                return CheckApkHasModTagFile(TempApk);
            }
            catch (Exception ex)
            {
                Log.LogErr("Error checking if temp apk is ready for install.", ex);
                throw new ModException("Error checking if temp apk is ready for install.", ex);
            }
        }

        public void CopyOriginalPackageApk(bool triggerUninstall)
        {
            UpdateStatus($"Locating installed {PackageName} app...");
            string bsApkPath = FindPackageApk();
            if (bsApkPath == null)
            {
                UpdateStatus($"Unable to find installed {PackageName} app!");
                throw new ModException($"{PackageName} does not seem to be installed, could not find its APK.");
            }
            UpdateStatus($"Copying original {PackageName} APK to temporary location...");
            TempApk = Path.Combine(_context.ExternalCacheDir.AbsolutePath, $"mod.{PackageName}.apk");
            try
            {
                File.Copy(bsApkPath, TempApk, true);
                UpdateStatus("APK copied successfully!");

                if (triggerUninstall)
                {
                    UpdateStatus($"Prompting user to uninstall {PackageName}...");
                    TriggerPackageUninstall(bsApkPath);
                }
            }
            catch (Exception ex)
            {
                UpdateStatus($"There was an error copying the original {PackageName} APK!");
                try
                {
                    File.Delete(TempApk);
                }
                catch
                { }
                throw new ModException("Problem copying original APK to temporary location.", ex);
            }
        }

        private void MakeFullPath(string path)
        {
            string[] splitPath = path.Split(Path.DirectorySeparatorChar, StringSplitOptions.RemoveEmptyEntries);
            string curPath = "";
            for (int i = 0; i < splitPath.Length; i++)
            {
                curPath = Path.Combine(curPath, splitPath[i]);
                if (!Directory.Exists(curPath))
                    Directory.CreateDirectory(curPath);
            }
        }

        //public void BackupOriginalApk()
        //{
        //    UpdateStatus($"Locating installed {PackageName} app...");
        //    string bsApkPath = FindPackageApk();
        //    if (bsApkPath == null)
        //    {
        //        UpdateStatus($"Unable to find installed {PackageName} app!");
        //        throw new ModException($"{PackageName} does not seem to be installed, could not find its APK.");
        //    }
        //    UpdateStatus("Verifying the installed APK isn't modded...");
        //    if (IsInstalledPackageModded)
        //    {
        //        UpdateStatus("Installed beatsaber IS modded!");
        //        if (File.Exists(Constants.BEATSABER_APK_BACKUP_FILE))
        //        {
        //            UpdateStatus("The APK backup already exists, not overwriting it with a modded one.");
        //        }
        //        else
        //        {
        //            UpdateStatus("WARNING: There is not an APK backup and the installed beatsaber is already modded!");
        //        }
        //        return;
        //    }
        //    UpdateStatus("Copying original Beat Saber APK to a backup location...");
        //    MakeFullPath(Constants.BACKUP_FULL_PATH);
        //    try
        //    {
        //        File.Copy(bsApkPath, Constants.BEATSABER_APK_BACKUP_FILE, true);
        //        UpdateStatus("Backup created.");
        //    }
        //    catch (Exception ex)
        //    {
        //        Log.LogErr($"Failed to copy beatsaber APK from {bsApkPath} to {Constants.BEATSABER_APK_BACKUP_FILE}", ex);
        //        UpdateStatus("Failed to make a backup of the original APK!");
        //        throw;
        //    }
        //}

        public void ApplyModToTempApk()
        {
            if (TempApk == null)
            {
                Log.LogErr("TempApk was null calling ModAndInstallPackageApk, don't know where the temp apk is.");
                UpdateStatus("Unable to find the temporary APK!");
                throw new ModException("Unable to find the temporary APK.");
            }

            if (FindPackageApk() != null)
            {
                UpdateStatus($"The {PackageName} app is still installed, it must be removed before modding and reinstalling.");
                Log.LogErr($"ModAndInstallPackageApk: {PackageName} is still installed.  It needs to be gone to continue.");
            }

            bool tempApkModified = false;
            bool modFailed = false;
            //keep track of any temp files that may have been used so we can clean them up
            List<string> tempFiles = new List<string>();
            try
            {
                //from this point on, the APK has been modified and isn't definitively recoverable if something goes wrong
                tempApkModified = true;

                //// modify classes.dex and inject the loadlibrary call for libmodloader.so
                InjectModLoaderToApk(TempApk, tempFiles);

                //// add libmodloader.so to the apk
                AddModLoaderToApk(TempApk);

                //// fix the manifest
                AddManifestModToApk(TempApk);

                //// add a 1 byte file to the APK so we know it's been modded to make verifying it later easier
                AddTagFileToApk(TempApk);

                //// re-sign the APK
                UpdateStatus("Re-signing the modded APK (this takes a minute)...");
                SignApk(TempApk);
            }
            catch (Exception ex)
            {
                Log.LogErr("Exception modding temp APK.", ex);
                UpdateStatus($"Something has gone wrong modding the APK!  You will need to reinstall {PackageName} and try again!");
                modFailed = true;
                throw ex;
            }
            finally
            {
                tempFiles.ForEach(x =>
                {
                    try
                    {
                        File.Delete(x);
                    }
                    catch (Exception ex)
                    {
                        Log.LogErr($"Could not remove temp file '{x}'!", ex);
                    }
                });
                if (modFailed && tempApkModified)
                {
                    Log.LogErr("The TempApk file is being deleted because something went wrong modding.");
                    try
                    {
                        var tempApk = TempApk;
                        TempApk = null;
                        File.Delete(tempApk);
                    }
                    catch (Exception ex)
                    {
                        Log.LogErr("Could not delete the TempApk file!", ex);
                    }
                }
            }
            UpdateStatus("Modding has completed!");
        }

        public void TriggerPackageInstall(string package = null)
        {
            if (TempApk == null)
                throw new Exception("TempApk is null, can't install it!");
            if (package == null)
                package = TempApk;
            if (_triggerInstall != null)
            {
                _triggerInstall(package);
                return;
            }
            PackageManager pkgMgr = _context.PackageManager;
            Intent intent = new Intent(Intent.ActionView);
            Android.Net.Uri apkURI = null;
            try
            {
                apkURI = FileProvider.GetUriForFile(
                             _context,
                             _context.PackageName + ".provider", new Java.IO.File(package));
            }
            catch (Exception ex)
            {

            }

            intent.SetDataAndType(apkURI, "application/vnd.android.package-archive");
            intent.AddFlags(ActivityFlags.GrantReadUriPermission);
            //intent.SetDataAndType(Android.Net.Uri.FromFile(new Java.IO.File(packageApkPath)), "application/vnd.android.package-archive");
            _context.StartActivity(intent);
            _tempApk = null;
        }

        //public void ClearHookMods()
        //{
        //    if (Directory.Exists(Constants.MODLOADER_MODS_PATH))
        //    {
        //        foreach (var file in Directory.GetFiles(Constants.MODLOADER_MODS_PATH))
        //        {
        //            if (!file.EndsWith("libbeatonmod.so"))
        //                try
        //                {
        //                    File.Delete(file);
        //                }
        //                catch (Exception ex)
        //                {
        //                    Log.LogErr($"Failed deleting mod {file}", ex);
        //                }
        //        }
        //    }
        //}

        public void UninstallPackage()
        {
            UpdateStatus($"Locating installed {PackageName} app...");
            string bsApkPath = FindPackageApk();
            if (bsApkPath == null)
            {
                UpdateStatus($"Unable to find installed {PackageName} app!");
                throw new ModException($"{PackageName} does not seem to be installed, could not find its APK.");
            }

            UpdateStatus("Triggering uninstall...");
            TriggerPackageUninstall(bsApkPath);
        }

        private void SignApk(string apkFilename)
        {
            try
            {
                using (var apk = new ZipFileProvider(apkFilename, FileCacheMode.None, false, FileUtils.GetTempDirectory()))
                {
                    ApkSigner signer = new ApkSigner(DebugCertificatePEM);
                    signer.Sign(apk);
                }
                UpdateStatus("APK signed!");
            }
            catch (Exception ex)
            {
                Log.LogErr($"Exception signing the APK {apkFilename}!", ex);
                UpdateStatus("Error re-signing the APK!");
                throw new ModException($"Exception signing the APK {apkFilename}!", ex);
            }
        }

        public void CleanupTempApk()
        {
            if (TempApk == null)
                return;

            try
            {
                File.Delete(TempApk);
                TempApk = null;
            }
            catch (Exception ex)
            {
                Log.LogErr("Unable to delete temp APK.", ex);
                throw new ModException("Unable to delete temp APK.", ex);
            }

        }

        private bool CheckApkHasModTagFile(string apkFilename)
        {
            using (var apk = new ZipFileProvider(apkFilename, FileCacheMode.None, true, FileUtils.GetTempDirectory()))
            {
                if (apk.FileExists(MOD_TAG_FILE))
                    return true;
            }
            return false;
        }

        private void UpdateStatus(string message)
        {
            StatusUpdated?.Invoke(this, message);
        }

        public void TriggerPackageUninstall(string packageApkPath)
        {
            if (_triggerUninstall != null)
            {
                _triggerUninstall(packageApkPath);
                return;
            }
            PackageManager pkgMgr = _context.PackageManager;

            Intent intent = new Intent(Intent.ActionDelete, Android.Net.Uri.FromParts("package",
                    pkgMgr.GetPackageArchiveInfo(packageApkPath, 0).PackageName, null));
            _context.StartActivity(intent);
        }

        private string FindPackageApk()
        {
            Intent mainIntent = new Intent(Intent.ActionMain, null);
            mainIntent.AddCategory(Intent.CategoryInfo);
            var pkgAppsList = _context.PackageManager.QueryIntentActivities(mainIntent, 0);
            foreach (var info in pkgAppsList)
            {

                if (info.ActivityInfo.PackageName == PackageName)
                {
                    return info.ActivityInfo.ApplicationInfo.PublicSourceDir;
                }
            }
            return null;
        }

        private string GetFromApkToFile(string apkFileName, string getFilename, string destinationFile = null)
        {
            string tempFile;
            if (destinationFile != null)
            {
                tempFile = destinationFile;
            }
            else
            {
                tempFile = Java.IO.File.CreateTempFile(getFilename, "", _context.ExternalCacheDir).AbsolutePath;
            }
            using (var apk = new ZipFileProvider(apkFileName, FileCacheMode.None, false, FileUtils.GetTempDirectory()))
            {
                using (var fs = File.Open(tempFile, FileMode.Create, FileAccess.ReadWrite))
                {
                    using (var readStream = apk.GetReadStream(getFilename, true))
                        readStream.CopyTo(fs);
                }
            }
            return tempFile;
        }

        private void SaveFileToApk(string apkFileName, string toFileName, string sourceFile)
        {
            using (var apk = new ZipFileProvider(apkFileName, FileCacheMode.None, false, FileUtils.GetTempDirectory()))
            {
                using (var fs = File.OpenRead(sourceFile))
                {
                    apk.QueueWriteStream(toFileName, fs, true, true);
                    apk.Save();
                }
            }
        }

        private void TryFindTempApk()
        {
            try
            {
                var tempApk = Path.Combine(_context.ExternalCacheDir.AbsolutePath, $"mod.{PackageName}.apk");
                if (File.Exists(tempApk))
                {
                    //TODO: more validation to make sure it isn't busted?
                    TempApk = tempApk;
                }
            }
            catch (Exception ex)
            {
                Log.LogErr("Exception trying to find the temp apk.", ex);
                _tempApk = null;
            }
        }

        private void InjectModLoaderToApk(string apkFilename, List<string> tempFiles)
        {
            try
            {
                UpdateStatus("Getting classes.dex from APK...");

                string classesDexTempFile = GetFromApkToFile(apkFilename, "classes.dex");
                tempFiles.Add(classesDexTempFile);
                string moddedClassesDexTempFile = Java.IO.File.CreateTempFile("moddedclasses.dex", "", _context.ExternalCacheDir).AbsolutePath;
                tempFiles.Add(moddedClassesDexTempFile);
                using (Com.Emulamer.Installerhelper.DexHelper dexHelper = new Com.Emulamer.Installerhelper.DexHelper())
                {
                    if (!dexHelper.InjectDexGeneric(new Java.IO.File(classesDexTempFile), new Java.IO.File(moddedClassesDexTempFile), "modloader", null))
                    {
                        UpdateStatus("classes.dex appears to already be modified");
                        Log.LogMsg("Tried to inject static constructor to classes.dex, but it seems to already have one.");
                    }
                    else
                    {
                        UpdateStatus("Writing modded classes.dex to the APK...");
                        SaveFileToApk(apkFilename, "classes.dex", moddedClassesDexTempFile);
                    }
                }
            }
            catch (Exception ex)
            {
                Log.LogErr($"Exception in {nameof(InjectModLoaderToApk)}!", ex);
                UpdateStatus("Error injecting modloader!");
                throw new ModException("Unable to inject mod loader!", ex);
            }
        }

        public string GetBeatSaberVersion()
        {
            if (!IsPackageInstalled)
                return null;

            try
            {
                Android.Content.PM.PackageInfo pInfo = _context.PackageManager.GetPackageInfo("com.beatgames.beatsaber", 0);
                return pInfo.VersionName;
            }
            catch (PackageManager.NameNotFoundException e)
            {
                Log.LogErr("The Beat Saber package could not be found!");
                throw;
            }
            catch (Exception ex)
            {
                Log.LogErr("Exception trying to determine Beat Saber version", ex);
                throw;
            }
        }

        private string GetAPKVersion(string fullApkPath)
        {
            try
            {
                Android.Content.PM.PackageInfo info = _context.PackageManager.GetPackageArchiveInfo(fullApkPath, 0);
                return info.VersionName;
            }
            catch (Exception ex)
            {
                Log.LogErr($"Exception trying to get version from APK '{fullApkPath}'", ex);
                throw;
            }
        }

        private List<string> GetMissingPermissions(string apkFilename, List<string> requiredPermissions)
        {
            try
            {
                var tt = _context.PackageManager.GetPackageArchiveInfo(apkFilename, PackageInfoFlags.Permissions);
                if (tt.RequestedPermissions == null)
                    return requiredPermissions.ToList();

                return requiredPermissions.Where(x => !tt.RequestedPermissions.Any(y => y == x)).ToList();
            }
            catch (Exception ex)
            {
                Log.LogErr($"Exception trying to check APK '{apkFilename}' for write external storage permission", ex);
                throw;
            }
        }

        private void AddAndroidPermissions(string apkFilename, List<string> permissions)
        {
            if (permissions == null || permissions.Count < 1)
                throw new ArgumentException("At least one permission must be specified to add.");
            try
            {
                using (var apk = new ZipFileProvider(apkFilename, FileCacheMode.None, false, FileUtils.GetTempDirectory()))
                {
                    byte[] manifest = apk.Read("AndroidManifest.xml");
                    AxmlWriter writer = new WritePermissionAxmlWriter(permissions);
                    AxmlReader reader = new AxmlReader(manifest);

                    reader.Accept(writer);
                    var outData = writer.ToByteArray();
                    apk.Write("AndroidManifest.xml", outData, true);
                    apk.Save();
                }
            }
            catch (Exception ex)
            {
                Log.LogErr("Exception trying to add permissions to AndroidManifest.xml", ex);
                throw;
            }
        }

        private class WritePermissionAxmlWriter : Pxb.Android.Axml.AxmlWriter
        {
            private List<string> _permissionsToAdd;
            public WritePermissionAxmlWriter(List<string> permissionsToAdd)
            {
                _permissionsToAdd = permissionsToAdd;
            }

            public override NodeVisitor Child(string ns, string name)
            {
                if (name == "manifest")
                {
                    var baseChild = base.Child(ns, name);
                    foreach (var permission in _permissionsToAdd)
                    {
                        var c = baseChild.Child(ns, "uses-permission");
                        c.Attr("http://schemas.android.com/apk/res/android", "name", 16842755, 3, new Java.Lang.String(permission));
                    }
                    return baseChild;
                }
                return base.Child(ns, name);
            }
        }

        private void AddManifestModToApk(string apkFilename)
        {
            UpdateStatus("Modding the manifest in the APK...");
            try
            {
                var permissions = GetMissingPermissions(apkFilename, new List<string>() { "android.permission.WRITE_EXTERNAL_STORAGE",
                                                                        "android.permission.READ_EXTERNAL_STORAGE",
                                                                        "android.permission.INTERNET" });
                if (permissions.Count < 1)
                {
                    Log.LogMsg($"APK '{apkFilename}' is not missing any required permissions in its manifest.");
                    return;
                }

                Log.LogMsg($"APK '{apkFilename}' is missing permissions: {string.Join(", ", permissions)}");
                AddAndroidPermissions(apkFilename, permissions);
            }
            catch (Exception ex)
            {
                Log.LogErr("Error modding the manifest in the APK", ex);
                UpdateStatus("Error modding the manifest in the APK!");
                throw new ModException("Error modding the manifest in the APK", ex);
            }
        }

        private void AddModLoaderToApk(string apkFilename)
        {
            UpdateStatus("Adding the libmodloader.so file to the APK...");
            try
            {
                using (var apk = new ZipFileProvider(apkFilename, FileCacheMode.None, false, FileUtils.GetTempDirectory()))
                {
                    if (apk.DirectoryExists(LIBMODLOADER_TARGET_FILE.GetDirectoryFwdSlash()))
                    {
                        apk.Write(LIBMODLOADER_TARGET_FILE, _modLoaderBytes, true);
                    }
                    if (apk.DirectoryExists(LIBMODLOADER_TARGET_FILE_64.GetDirectoryFwdSlash()))
                    {
                        apk.Write(LIBMODLOADER_TARGET_FILE_64, _modLoaderBytes64, true);
                    }
                    apk.Save();
                }
            }
            catch (Exception ex)
            {
                Log.LogErr("Error adding libmodloader.so to APK", ex);
                UpdateStatus("Error adding modloader to the APK!");
                throw new ModException("Error adding libmodloader.so to APK", ex);
            }
        }

        //private void InstallAssetRedirectMod()
        //{
        //    UpdateStatus("Installing asset redirection mod ...");
        //    try
        //    {
        //        string dirName = Constants.MODLOADER_MODS_PATH;
        //        try
        //        {
        //            if (!Directory.Exists(dirName))
        //            {
        //                Log.LogMsg($"Mods target directory doesn't exist, creating {dirName}");
        //                Directory.CreateDirectory(dirName);
        //            }
        //        }
        //        catch (Exception ex)
        //        {
        //            Log.LogErr($"Unable to create directory {dirName}!", ex);
        //            UpdateStatus("Failed to create mods directory in external storage!");
        //            throw new ModException($"Unable to create directory {dirName}!", ex);
        //        }
        //        using (var resStream = _context.Resources.OpenRawResource(Resource.Raw.libbeatonmod))
        //        {
        //            using (var fs = File.Open(Path.Combine(Constants.MODLOADER_MODS_PATH, "libbeatonmod.so"), FileMode.Create, FileAccess.Write))
        //            {
        //                resStream.CopyTo(fs);
        //            }
        //        }
        //    }
        //    catch (Exception ex)
        //    {
        //        Log.LogErr("Error copying libbeatonmod.so!", ex);
        //        UpdateStatus("Error installing asset redirection mod!");
        //        throw new ModException("Error copying libbeatonmod.so", ex);
        //    }
        //}

        private void AddTagFileToApk(string apkFilename)
        {
            using (var apk = new ZipFileProvider(apkFilename, FileCacheMode.None, false, FileUtils.GetTempDirectory()))
            {
                if (apk.FileExists(MOD_TAG_FILE))
                {
                    Log.LogMsg("APK file already had the mod's tag file.");
                    return;
                }
                apk.Write(MOD_TAG_FILE, new byte[1], true, false);
                apk.Save();
            }
        }
        private const string DebugCertificatePEM = @"-----BEGIN CERTIFICATE-----
MIICpjCCAY6gAwIBAgIITpLEzAv/BWIwDQYJKoZIhvcNAQELBQAwEjEQMA4GA1UE
AwwHVW5rbm93bjAgFw0wOTA2MDIwMDAwMDBaGA8yMDY5MDYwMjAwMDAwMFowEjEQ
MA4GA1UEAwwHVW5rbm93bjCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB
AKTjqOckhu7QSfheDcFOtMmq3oYagrybDyIvUkQQfD5bN03dGq+3eD4N5OgZTip5
+W3WCWZCqQESwb2spb9Wx7QLYOeZb8FXlGIwo5d6nvRFHKm4Bomr37t0NcSK+JRD
a3/MOgPP5KQJ5L/z3RCZBKxn0zZBcrUrBLI/0z6kFFCmIo9b/TDQf8Si+mCeM8fu
dH32TTPVUk1mrhssOkykhsxCPbpHzZIj3TKGk04g2es1SlIEgQIldWswa4xkTjny
C7pi3hhpQuLKUpYO2GHhT5aq4J2rpZVScEzLiNckM9iyC+9MdWyG++hlrSb9GeAn
rwqiHN9BjYt8BtvpEDGahMcCAwEAATANBgkqhkiG9w0BAQsFAAOCAQEAAzWf0UuC
ZK7UWnyXltiAqmIHGduEVNaU8gQHvYlS7UiYWgieC2MhYcpojIWf78/n6TP46xUj
Zcs2WHw4M76ppp4Z0t32T4wKMV64rvxmxrT1rnrocpalHEW0L7o6npPwQdin58kY
ip+5dNleQmeFy8E/Plew3E3JiQKedfIR9xj3BNFr4cZHhuIk8bMXi8v4p7dr6A+4
cCYOowy93Oirb1z9RBQqaPQZkQWVH+LaRQ95CMu688hksVXUZz6ZcRzxtQsMmKj3
r/4yonSyufkTY2Sky0myL04/gbDCqLSi1CLo0ksFSRi7d9oChCtNewNoXByGq09X
09SW0xPRYHxoSA==
-----END CERTIFICATE-----
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEApOOo5ySG7tBJ+F4NwU60yarehhqCvJsPIi9SRBB8Pls3Td0a
r7d4Pg3k6BlOKnn5bdYJZkKpARLBvaylv1bHtAtg55lvwVeUYjCjl3qe9EUcqbgG
iavfu3Q1xIr4lENrf8w6A8/kpAnkv/PdEJkErGfTNkFytSsEsj/TPqQUUKYij1v9
MNB/xKL6YJ4zx+50ffZNM9VSTWauGyw6TKSGzEI9ukfNkiPdMoaTTiDZ6zVKUgSB
AiV1azBrjGROOfILumLeGGlC4spSlg7YYeFPlqrgnaullVJwTMuI1yQz2LIL70x1
bIb76GWtJv0Z4CevCqIc30GNi3wG2+kQMZqExwIDAQABAoIBAC0gYUlhJcyWFKh0
lS8iazgGG4B4IO+dQDcK3GjkWhx2ulwE9xjADZhuFQewZUQavbjhqxDhjX9NsthG
N9Z12ZHcy1iXFY7EeUemKB9836Pahk2sn51t/H1BALYZko6BJRqEuhvw+ZIrYv9l
rkqslirY/2UJ5GrQqyhdb2LlZOntHFDwYesZsKxj0v+IV4P9eRcwtEYr2M1AzZPb
qIEx1v+P6DpZsWDViUpzkfcjqYziViEeXIgkjeaQYkzCwn7h/iTT6WC/VUrMTGzB
mZ4wsDinrMTLQBYqaafmX7Ff172u8D7fIyjTLJjx9mbG3hWSJPfbPl1lDaw+tWrW
aoyZXgECgYEA7MHb8FM5xksv2UEpEDJY9IZbIHWNk+sGZv13bwP5AxMJYfWy0wpe
hGoqc49TSwG8EZwLhfvAtA0BXDXLI3+biulnO3JU6hgAeSzQyk3RQFjB08QM7CbQ
Uzb3T2pRgjRJdFgrRlUBtj19VC2sTR/zUqVSSxAniKGMRQ4zoIToINECgYEAskp2
3/EQDEj4u64Ggi5KaJtvKiITO9tGFt0svSuFCCgcM4sBg6EFX6JEbMfbepRZ5GTW
h9W8XLo9jIZBQYqLhuKJtJ+PlEBgAxK4JAEwgqmWTcHBXdYJicFVJMLsmQOK4HiJ
hNgsIaQTvyhl9/aNgJA96wjUb//pVsqSMNSa8hcCgYBxoUFMAMWz1BYs8UciDOgA
xBMsav7+RUiXWYNe9ssmnJZeO6wN+eYPK10ghWN2lmiLExe8wG1mfO9wMClE6lPe
wdLYBzGWANsJTWcQEXUiqvasCmYhWSeXKMRdiyt/kFTI0CBE6zudGbnzEtClW3ZO
7iWm/SPcQZyu7/f7TI6UYQKBgAGYzyXEV/t0L94meeJynbIAKme7NGbl2OPdiUgM
er2O9mmzxgiyyYSIxIog5CNd7swv5wgCbxR5ipGWpkD7B7LmlosqnrOaPAHrCgEw
jYmuES2THbNEdoNoWuXgZRQdxwGpsrmg4gxPFuowZ3FoIO5U3GkdhCGYrjNbzyFm
1hhzAoGAV6iFwnriGgTLQEz4Pjviqq05SrS2+6jvP6siB9I7GBPlSIQSBMPdyCKA
8hebhfmRmEjRzPxqxKAE3d68MIeZ3n5g0IFcPL+ps3u937qmsttKWgubjkBTr2Ot
hEJ9cirq8PX32lYS3Q5lHaFjlzNgVvijDQCFuxA4NOj+hDFfC/Q=
-----END RSA PRIVATE KEY-----";
    }
}