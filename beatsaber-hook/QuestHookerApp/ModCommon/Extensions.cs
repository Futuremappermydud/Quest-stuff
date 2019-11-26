using System;
using System.IO;

namespace ModCommon
{
    public static class Extensions
    {
        public static string GetDirectoryFwdSlash(this string path)
        {
            if (!path.Contains("/"))
                return "";

            return path.Substring(0, path.LastIndexOf('/'));
        }
        public static byte[] ReadBytes(this Stream stream, int count)
        {
            byte[] bytes = new byte[count];
            stream.Read(bytes, 0, count);
            return bytes;
        }
        public static string FullMessage(this Exception exception)
        {
            if (exception == null)
                return "(Exception was null!)";

            string exmsg = "";
            exmsg = $"{exception.Message} {exception.StackTrace}";
            var ex = exception.InnerException;
            while (ex != null)
            {
                exmsg += $"\nInnerException: {ex.Message} {ex.StackTrace}";
                ex = ex.InnerException;
            }
            return exmsg;
        }

        public static string GetFilenameFwdSlash(this string path)
        {
            if (path == "/")
                return "";

            if (!path.Contains("/"))
                return path;

            if (path.EndsWith("/"))
                path = path.TrimEnd('/');

            int idx = path.LastIndexOf('/') + 1;

            return path.Substring(idx, path.Length - idx);
        }

        public static string CombineFwdSlash(this string path1, string path2)
        {
            if (path1 == null || path2 == null)
                return null;

            if (path1.EndsWith("/") && path1.Length > 1)
                path1 = path1.TrimEnd('/');

            path2 = path2.TrimStart('/');

            if (string.IsNullOrWhiteSpace(path1))
                return path2;

            if (string.IsNullOrWhiteSpace(path2))
                throw new ArgumentException("Path 2 is required!");

            return path1 + "/" + path2;
        }
      
        public static string RemoveSuffix(this string value, string suffix)
        {
            if (!value.EndsWith(suffix))
                return value;
            //don't remove it if that's all there is
            if (value == suffix)
                return value;

            return value.Substring(0, value.Length - suffix.Length);
        }

    }
}
