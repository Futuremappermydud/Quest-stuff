using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;


namespace ModCommon
{
    public class ModException : Exception
    {
        public ModException(string message, Exception innerException) : base(message, innerException)
        { }

        public ModException(string message) : base(message)
        { }
    }
}