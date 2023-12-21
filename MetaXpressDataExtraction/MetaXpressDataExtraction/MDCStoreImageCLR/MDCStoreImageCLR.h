#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <vcclr.h>
#include "MDCStoreImageLib.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace System::Runtime::InteropServices;

namespace MDCStoreImageCLR 
{
	public ref class MDCStoreUtils
	{
	public:
		bool CLR_MDCStoreUtils_Init()
		{
			return Lib_MDCStoreUtils_Init();
		}
		void CLR_UserLoginAndGetImag(String^ UserName, String^ Password, String^ DSN, String^ DBName, int PlateId)
		{
			msclr::interop::marshal_context context;
			std::string strUserName = context.marshal_as<std::string>(UserName);
			std::string strPassword = context.marshal_as<std::string>(Password);
			std::string strDSN = context.marshal_as<std::string>(DSN);
			std::string strDBName = context.marshal_as<std::string>(DBName);
			Lib_GetImage(strUserName, strPassword, strDSN, strDBName, PlateId);
		}
	};
}
