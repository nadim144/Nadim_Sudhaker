#pragma once

#include "resource.h"
//#include "MDCStoreUtilsApi.h"
#include <string>
extern "C"
{
	__declspec(dllexport) bool Lib_MDCStoreUtils_Init();
	//__declspec(dllexport) void Lib_UserLoginAndGetImage(string UserName, string Password, string DSN, string DBName, int PlateId);
	__declspec(dllexport) bool Lib_GetImage(std::string, std::string, std::string, std::string, int);
}