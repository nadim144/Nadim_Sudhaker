
//******************************************************************************
//   
// Copyright (c) 2005 Molecular Devices
// All rights reserved.
//******************************************************************************
// Module:  GetSitesByPlate_CallBack.cpp
// Purpose: Provide functions to process data and get all Site IDs belonging to a plate
//  
/////////////////////////////////////////////////////////////////////////////////
//#include "StdAfx.h"
#include "pch.h"
#include ".\MDCS_PLATE_GetSitesByPlate_CallBack.h"
#include <iostream>
using namespace std;

//==============================================================================================
// FUNCTION: Constructor
// PARAMETER: 
//		m_plarrSieIDs - pointer to array which stores all siteid returned from db.
//==============================================================================================
MDCS_PLATE_GetSitesByPlate_CallBack::MDCS_PLATE_GetSitesByPlate_CallBack(CArray<LONGLONG, LONGLONG>* parrSiteID): m_plarrSiteIDs(parrSiteID)
{
}


//==============================================================================================
// FUNCTION: GetNextResult
// PURPOSE: Called to get next row of data
//==============================================================================================
BOOL MDCS_PLATE_GetSitesByPlate_CallBack::GetNextResult(MDCS_QueryResults* pQueryRes)
{
    ASSERT(pQueryRes);
    if (!pQueryRes)
        return TRUE;

    //check if data is empty - if it is empty, function will return -LLONG_MAX 
    LONGLONG lValue = pQueryRes->GetLongValue("SITE_ID");
    if (lValue == -LLONG_MAX)
    {
        return TRUE;
    }
    m_plarrSiteIDs->Add(lValue);

    return TRUE;
}

