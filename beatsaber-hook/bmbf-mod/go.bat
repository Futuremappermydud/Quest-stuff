adb shell logcat -c
mkdir /sdcard/Android/data/com.beatgames.beatsaber
mkdir /sdcard/Android/data/com.beatgames.beatsaber/files
mkdir /sdcard/Android/data/com.beatgames.beatsaber/files/mods
call ..\build.bat
adb shell am start -n com.beatgames.beatsaber/com.unity3d.player.UnityPlayerActivity

