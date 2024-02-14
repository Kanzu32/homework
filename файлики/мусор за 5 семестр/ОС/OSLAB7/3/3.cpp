#include <Windows.h>
#include <iostream>
#include "3.h"

using namespace std;


DLL3_API void printMetrics() {
	int n = GetSystemMetrics(SM_CMOUSEBUTTONS);
	wcout << "Number of mouse buttons: " << n << endl;
	n = GetSystemMetrics(SM_CXMAXIMIZED);
	wcout << "Width of a maximized window: " << n << endl;
	n = GetSystemMetrics(SM_CYMAXIMIZED);
	wcout << "Height of a maximized window: " << n << endl;
	n = GetSystemMetrics(SM_CXVSCROLL);
	wcout << "Width of a vertical scroll bar: " << n << endl;
	n = GetSystemMetrics(SM_CYVSCROLL);
	wcout << "Height of the arrow bitmap on a vertical scroll bar: " << n << endl;
}