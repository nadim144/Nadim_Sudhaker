// MDCStoreImageLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include <iostream>
#include "framework.h"
#include "MDCStoreImageLib.h"
#include "MDCStoreUtilsApi.h"
#include "MDCS_PLATE_GetSitesByPlate_CallBack.h"
#include "MDCS_ASSAY_GetAllForPlate_CallBack.cpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;


extern "C" __declspec(dllexport) bool Lib_MDCStoreUtils_Init()
{
	return MDCStoreUtils_Init();
}

extern "C" __declspec(dllexport) bool Lib_GetImage(string UserName, string Password, string DSN, string DBName, int PlateId)
{
	MDCS_ST_UserLogin uLoging;
	strncpy_s(uLoging.szUserName, UserName.c_str(), min(sizeof(uLoging.szUserName) - 1, strlen(UserName.c_str())));
	strncpy_s(uLoging.szPassword, Password.c_str(), min(sizeof(uLoging.szUserName) - 1, strlen(Password.c_str())));
	strncpy_s(uLoging.szDSN, DSN.c_str(), min(sizeof(uLoging.szUserName) - 1, strlen(DSN.c_str())));
	strncpy_s(uLoging.szDatabase, DBName.c_str(), min(sizeof(uLoging.szUserName) - 1, strlen(DBName.c_str())));

	//get database handle 
	MDCS_DBHandleSmartPtr ptrDB(uLoging);

	if (ptrDB.GetHandle())
	{
		cout << "GetHandle " << ptrDB.GetHandle() << " Value.\n" << endl;
		cout << "PlateId " << PlateId << " Value.\n" << endl;

		/* 1. MDCS_PLATE_GetSitesByPlate() API*/
		//Get all sites belonging to the plate
		//======================================

		CArray<LONGLONG, LONGLONG> larrSiteIDs;
		MDCS_PLATE_GetSitesByPlate_CallBack pResultSites(&larrSiteIDs);
		//Call function in MDCStoreutilsapi
		if (!MDCS_PLATE_GetSitesByPlate(ptrDB.GetHandle(), PlateId, &pResultSites))
		{
			return FALSE;
		}
		else
		{
			_tprintf(_T("No sites were found for the selected plate"));
			return FALSE;
		}


		/* 1. MDCS_PLATE_GetSitesByPlate() API*/
		//Get all sites belonging to the plate
		//======================================

		CArray<LONGLONG, LONGLONG> assayIDs;
		CArray<LPCSTR, LPCSTR> assayNames;
		CArray<LPCSTR, LPCSTR> assayDescriptions;
		CArray<LPCSTR, LPCSTR> createdbys;

		//std::list<AssayPlate> assayPlateLis;

		//MDCS_ASSAY_GetAllForPlate_CallBack pResult(&assayPlateLis);

		MDCS_ASSAY_GetAllForPlate_CallBack pResult(&assayIDs, &assayNames, &assayDescriptions, &createdbys);
		if (MDCS_ASSAY_GetAllForPlate(ptrDB.GetHandle(), PlateId, &pResult))
		{
			cout << "MDCS_ASSAY_GetAllForPlate() API call Succesful .." << endl;
			cout << "assayIDs[0] = " << assayIDs[0] << endl;
		}

	}
	else
	{
		cout << "Execution canceled." << endl;
	}
	return true;

}

//BOOL MDCS_ASSAY_GetMeasurementInfoByAssayAndPlate(HDBHANDLE hHandle, LONGLONG lAssayID, LONGLONG lPlateID)
//{
//	 CArray<LONGLONG, LONGLONG> larrSiteIDs;
//	 CGetAllForPlate_CallBack pResult(&larrSiteIDs);
//	 if (!MDCS_ASSAY_GetMeasurementInfoByAssayAndPlate(hDBHandle, lPlateID, &pResult)) {
//		 return FALSE;
//	 }
//	 else
//	 {
//		 return TRUE;
//	 }
//	return TRUE;
//}



int main()
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(nullptr);

	if (hModule != nullptr)
	{
		// initialize MFC and print and error on failure
		if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
		{
			// TODO: code your application's behavior here.
			wprintf(L"Fatal Error: MFC initialization failed\n");
			nRetCode = 1;
		}
		else
		{
			// TODO: code your application's behavior here.
		}
	}
	else
	{
		// TODO: change error code to suit your needs
		wprintf(L"Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}

	return nRetCode;
}
// TODO: This is an example of a library function
void fnMDCStoreImageLib()
{
}

//MDCS_ASSAY_GetAllForPlate


BOOL GetAllForPlate(HDBHANDLE hDBHandle, LONGLONG lPlateID)
{
	/*Purpose
		Function to get all assays that are associated with a plate.
		Parameters
		hHandle - database connection handle
		lPlateID - ID of a plate
		pResultCallback - pointer to a callback function to get data
		Output
		Columns :
	ASSAY_ID - assay ID
		ASSAY_NAME - assay name
		ASSAY_DESC - assay description
		CREATOR_NAME - name of the user who created the assay
		Return
		FALSE - if error occurred*/
		// CArray<LONGLONG, LONGLONG> larrSiteIDs;
		 //CGetAllForPlate_CallBack pResult(&larrSiteIDs);
		 /*if (!MDCS_ASSAY_GetAllForPlate(hDBHandle, lPlateID, &pResult))
		 {
			 return FALSE;
		 }
		 else
		 {
			 return TRUE;
		 }*/

	return false;
}


//BOOL GetMeasurementsBySiteID(HDBHANDLE hDBHandle, LONGLONG lPlateID)
//{
//    /*Purpose
//        To get measurements by site ID.
//        Parameters
//        hHandle - database connection handle
//        lSiteID - site ID
//        pResultCallback - pointer to callback function to get data
//        Output
//        Columns :
//    TABLE_ID - table name
//        COLUMN_NAME
//        ASSAY_ID
//        COLUMN_TYPE
//        COLUMN_NAME_EXT*/
//    CArray<LONGLONG, LONGLONG> larrSiteIDs;
//    CGetAllForPlate_CallBack pResult(&larrSiteIDs);
//    if (!MDCS_ASSAY_GetMeasurementsBySiteID(hDBHandle, lPlateID, &pResult))
//    {
//        return FALSE;
//    }
//    else { return true; }
//}


//BOOL GetPlateInfo(HDBHANDLE hDBHandle, LONGLONG lPlateID)
//{
//	cout << "hDBHandle " << hDBHandle << " was not found.\n" << endl;
//	MDCS_ST_PlateInfo st_PlateInfo;
//	cout << "Retrieve plate info " << endl;
//	if (!MDCS_PLATE_GetInfo(hDBHandle, lPlateID, st_PlateInfo))
//		return FALSE;
//	else
//	{
//		if (!st_PlateInfo.lPlateID)
//		{
//			cout << "Plate with Plate ID " << lPlateID << " was not found.\n" << endl;
//			return FALSE;
//		}
//
//		// Print out plate info
//		cout << "The plate info " << endl;
//		cout << "Plate ID:\t" << lPlateID << endl;
//		cout << "Plate name:\t" << st_PlateInfo.szPlateName << endl;
//		cout << "Xwells:\t" << st_PlateInfo.nXWells << endl;
//		cout << "Ywells:\t" << st_PlateInfo.nYWells << endl;
//		cout << "Aquisition:\t" << st_PlateInfo.szAcqName << endl;
//		cout << "Barcode:\t" << st_PlateInfo.szBarcode << endl;
//		cout << "Creator:\t" << st_PlateInfo.szCreator << endl;
//		cout << "Description:\t" << st_PlateInfo.szDesc << endl;
//		cout << "\n\n";
//	}
//	return TRUE;
//}
