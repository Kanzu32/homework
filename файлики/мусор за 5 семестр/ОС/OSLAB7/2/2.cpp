#pragma warning(disable : 4996)

#include <Windows.h>
#include <ShlObj.h>
#include <iostream>
#include "2.h"

using namespace std;


SAMPLEDLL_API void printAllPaths() {
	TCHAR buffer[MAX_PATH + 1];
	SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_COMMON_APPDATA, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_COMMON_DOCUMENTS, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_HISTORY, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_INTERNET_CACHE, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_PROGRAM_FILES_COMMON, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_SYSTEM, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
	SHGetFolderPath(NULL, CSIDL_WINDOWS, NULL, SHGFP_TYPE_DEFAULT, buffer);
	wcout << buffer << endl;
}

SAMPLEDLL_API void printWindowsVersion() {
	OSVERSIONINFO osvi;
	ZeroMemory(&osvi, sizeof(OSVERSIONINFO));
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx((OSVERSIONINFO*)&osvi);

	wcout << "Major ver: " << osvi.dwMajorVersion << "\nMinor ver: " << osvi.dwMinorVersion << "\nBuild: " << osvi.dwBuildNumber << "\nPlatform: " << osvi.dwPlatformId << endl;
}

SAMPLEDLL_API void printTime() {
	TCHAR buffer[100];
	TCHAR format[20] = L"ddd',' MMM dd yy";
	GetDateFormatEx(LOCALE_NAME_SYSTEM_DEFAULT, NULL, NULL, TEXT("yyyy'-'M'-'d"), buffer, 100, NULL);
	wcout << buffer << endl;
	GetTimeFormatEx(LOCALE_NAME_INVARIANT, NULL, NULL, TEXT("h':'m':'s t"), buffer, 100);
	wcout << buffer << endl;

}