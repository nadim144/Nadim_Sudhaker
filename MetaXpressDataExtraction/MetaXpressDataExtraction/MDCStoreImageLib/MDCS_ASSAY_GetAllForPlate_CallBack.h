#pragma once
//******************************************************************************
//   
// Copyright (c) 2005 Molecular Devices
// All rights reserved.
//******************************************************************************
// Module:  MDCS_ASSAY_GetAllForPlate_CallBack.h
// Purpose: Provide functions to process data and get all Site IDs belonging to a plate
//  
/////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "mdcstoreutilsapi.h"
#include <afxtempl.h>

class MDCS_ASSAY_GetAllForPlate_CallBack: public MDCS_GetDBResultsCCallback
{
public:
    MDCS_ASSAY_GetAllForPlate_CallBack(CArray<LONGLONG, LONGLONG>* m_plarrAssayID,
        CArray<LPCSTR, LPCSTR>* m_plarrAssayName,
        CArray<LPCSTR, LPCSTR>* m_plarrAssayDescription,
        CArray<LPCSTR, LPCSTR>* m_plarrcreatedby);

   //MDCS_ASSAY_GetAllForPlate_CallBack(std::list<AssayPlate> assayPlateLis);

    virtual ~MDCS_ASSAY_GetAllForPlate_CallBack(void) {}

    //called to get next row of data
    virtual BOOL GetNextResult(MDCS_QueryResults* pQueryRes);

    //called to get number of results
    virtual void SetResultNumber(LONGLONG nCount)
    {};

    //called when there is an error 
    virtual void Error(LPCSTR pErrorText)
    {
        return;
    }

    //called when completely done
    virtual void Done()
    {
        return;
    }

    //called by functions to check if results should be returned in their original format
    virtual BOOL ProcessResultsInOriginalFormat() const
    {
        return TRUE;
    }

    //called to get info about results structure (field names and types)
    //all fields  will be empty
    virtual BOOL GetResultInfo(MDCS_QueryResults* pQueryRes) { return TRUE; };


private:
    // hide the default copy constructors
    MDCS_ASSAY_GetAllForPlate_CallBack(MDCS_GetDBResultsCCallback const&);
    const MDCS_ASSAY_GetAllForPlate_CallBack& operator=(MDCS_GetDBResultsCCallback const&);

    //pointer to array of site ID 

    CArray<LONGLONG, LONGLONG>  * m_plarrAssayID;
    CArray<LPCSTR, LPCSTR>      * m_plarrAssayName;
    CArray<LPCSTR, LPCSTR>      * m_plarrAssayDescription;
    CArray<LPCSTR, LPCSTR>      * m_plarrcreatedby;
   
    //std::list<AssayPlate> assayPlateList;

};
