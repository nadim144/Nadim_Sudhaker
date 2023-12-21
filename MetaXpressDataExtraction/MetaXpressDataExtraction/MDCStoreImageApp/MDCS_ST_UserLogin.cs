using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
namespace MDCStoreImageApp
{
    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 0)]
    public struct MDCS_ST_UserLogin
    {
        [MarshalAs(UnmanagedType.I8)] long lUserLoginID;            // User ID
        [MarshalAs(UnmanagedType.I8)] long lUserGroupID;            // Group ID
        [MarshalAs(UnmanagedType.I4)] int eUserStatus;              // User Status (21=RO, 22=RW, 23=LabHead)
        [MarshalAs(UnmanagedType.Bool)] public bool bUseServer;     // True = Server name, not ODBC name
        [MarshalAs(UnmanagedType.Bool)] public bool bUseTrusted;    // True = Use a trusted connection
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 50)]
        public string szUserName;                                   // User name
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
        public string szPassword;                                   // User password
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
        public string szDSN;                                        // Datasource name 
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 256)]
        public string szDatabase;                                   // Database name

    }
}
