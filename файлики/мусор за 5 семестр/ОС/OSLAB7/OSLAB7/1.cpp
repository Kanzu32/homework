#include <Windows.h>
#define SECURITY_WIN32
#include <Security.h>
#include <iostream>
#include "1.h"

using namespace std;


void printComputerName() {
    DWORD length = 100;
    TCHAR buffer[100];
    GetComputerName(buffer, &length);
    wcout << L"Computer name: " << buffer << endl;
}

void printComputerDomain() {
    DWORD length = 0;
    TCHAR buffer[100];
    GetComputerNameEx(ComputerNamePhysicalDnsHostname, NULL, &length);
    GetComputerNameEx(ComputerNamePhysicalDnsHostname, buffer, &length);
    wcout << L"Domain name: " << buffer << endl;
}

void printUserName() {
    DWORD length = 100;
    TCHAR buffer[100];
    GetUserName(buffer, &length);
    wcout << L"Username: " << buffer << endl;
}

void printFullUserName() {
    DWORD length = 0;
    TCHAR buffer[100];
    GetUserNameEx(NameSamCompatible, NULL, &length);
    GetUserNameEx(NameSamCompatible, buffer, &length);
    wcout << L"Full username: " << buffer << endl;
}