#include <Windows.h>
#include <iostream>
#include "4.h"

using namespace std;

int main() {
	printParameters();
}

DLL4_API void printParameters() {
	SERIALKEYS param1;
	ZeroMemory(&param1, sizeof(SERIALKEYS));
	param1.cbSize = sizeof(SERIALKEYS);
	SystemParametersInfo(SPI_GETSERIALKEYS, sizeof(SERIALKEYS), &param1, 0);
	wcout << "State of serial port (only on Win95/98): " << param1.iPortState << endl;
	HKL param2;

	SystemParametersInfo(SPI_GETDEFAULTINPUTLANG, sizeof(HKL), &param2, 0);
	wcout << "Input locale identifier for the system default input language: " << param2 << endl;
}