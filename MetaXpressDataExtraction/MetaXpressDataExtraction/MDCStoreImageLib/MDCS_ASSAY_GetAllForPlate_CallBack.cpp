
//******************************************************************************
//   
// Copyright (c) 2005 Molecular Devices
// All rights reserved.
//******************************************************************************
// Module:  MDCS_ASSAY_GetAllForPlate_CallBack.cpp
// Purpose: Provide functions to process data and get all Site IDs belonging to a plate
//  
/////////////////////////////////////////////////////////////////////////////////
//#include "StdAfx.h"
#include "pch.h"
#include ".\MDCS_ASSAY_GetAllForPlate_CallBack.h"
#include <iostream>
using namespace std;

//==============================================================================================
// FUNCTION: Constructor
// PARAMETER: 
//		m_plarrSieIDs - pointer to array which stores all siteid returned from db.
//==============================================================================================

MDCS_ASSAY_GetAllForPlate_CallBack::MDCS_ASSAY_GetAllForPlate_CallBack(CArray<LONGLONG, LONGLONG>* m_plarrAssayID,
    CArray<LPCSTR, LPCSTR>* m_plarrAssayName,
    CArray<LPCSTR, LPCSTR>* m_plarrAssayDescription,
    CArray<LPCSTR, LPCSTR>* m_plarrcreatedby) : m_plarrAssayID(m_plarrAssayID), m_plarrAssayName(m_plarrAssayName), m_plarrAssayDescription(m_plarrAssayDescription), m_plarrcreatedby(m_plarrcreatedby)
{
}

//MDCS_ASSAY_GetAllForPlate_CallBack::MDCS_ASSAY_GetAllForPlate_CallBack(std::list<AssayPlate> assayPlateList) : assayPlateList(assayPlateList)
//{
//}

//==============================================================================================
// FUNCTION: GetNextResult
// PURPOSE: Called to get next row of data
//==============================================================================================
BOOL MDCS_ASSAY_GetAllForPlate_CallBack::GetNextResult(MDCS_QueryResults* pQueryRes)
{
    ASSERT(pQueryRes);
    if (!pQueryRes)
        return TRUE;

    //check if data is empty - if it is empty, function will return -LLONG_MAX 
    LONGLONG assayID = pQueryRes->GetLongValue("ASSAY_ID");
    LPCSTR assayName = pQueryRes->GetStringValue(LPCSTR("ASSAY_NAME"));
    LPCSTR assayDesc = pQueryRes->GetStringValue(LPCSTR("ASSAY_DESC"));
    LPCSTR creatorName = pQueryRes->GetStringValue(LPCSTR("CREATOR_NAME"));
    if (assayID == -LLONG_MAX)
    {
        return TRUE;
    }

    m_plarrAssayID->Add(assayID);
    m_plarrAssayName->Add(assayName);
    m_plarrAssayDescription->Add(assayDesc);
    m_plarrcreatedby->Add(assayName);
   
    //assayPlateList.push_back(AssayPlate(assayName, assayID));
    return TRUE;

}

