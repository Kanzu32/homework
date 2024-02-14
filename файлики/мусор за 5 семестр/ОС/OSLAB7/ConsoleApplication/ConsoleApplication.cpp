#pragma comment(lib, "1.lib")
#pragma comment(lib, "2.lib")
#include "1.h"
#include "2.h"
#include "4.h"
#include <iostream>
#include <Windows.h>
#include <delayimp.h>

using namespace std;

typedef void (*PRINT_METRICS)();

int main() {
    cout << "Task 1" << endl;
    printComputerName();
    printComputerDomain();
    printUserName();
    printFullUserName();

    cout << endl << "Task 2" << endl;
    printAllPaths();
    printWindowsVersion();
    printTime();

    cout << endl << "Task 3" << endl;
    HMODULE hDLL = LoadLibrary(TEXT("3.dll"));
    if (NULL != hDLL) {
        PRINT_METRICS func = (PRINT_METRICS)GetProcAddress(hDLL, "printMetrics");
        if (NULL != func) func();
        FreeLibrary(hDLL);
    }

    cout << endl << "Task 4" << endl;
    printParameters();
    __FUnloadDelayLoadedDLL2("4.dll");
}

