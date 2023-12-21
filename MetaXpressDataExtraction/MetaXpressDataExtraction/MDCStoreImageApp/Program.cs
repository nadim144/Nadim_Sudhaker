using System;
//using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MDCStoreImageCLR;



namespace MDCStoreImageApp
{
    class Program
    {
        static void Main(string[] args)
        {
            MDCStoreUtils mDCStoreUtils = new MDCStoreUtils();           
            if(mDCStoreUtils.CLR_MDCStoreUtils_Init())
            {
                Console.WriteLine("MDCStoreUtils_Init() API Sucessfully called ..");
            }           
            MDCS_ST_UserLogin loginInfo = new MDCS_ST_UserLogin
            {
                szUserName = "MDCadmin",
                szPassword = "Software1!",
                szDSN = "DB_ImagExpress", 
                szDatabase = "MDCStore"
            };
            mDCStoreUtils.CLR_UserLoginAndGetImag(loginInfo.szUserName, loginInfo.szPassword, loginInfo.szDSN, loginInfo.szDatabase, 536);
        }
    }
}
