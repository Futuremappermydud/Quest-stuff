using System;
using System.Collections.Generic;
using System.Text;

namespace ModCommon
{
    public enum FileCacheMode
    {
        //None won't work for some stuff since it can't seek.
        None,
        Memory,
        TempFiles
    };
}
