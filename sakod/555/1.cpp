#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <vector>

#pragma comment(lib, "Ws2_32.lib")

using namespace std;

int main () {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    WSADATA wsData;
		
    int erStat = WSAStartup(MAKEWORD(2,2), &wsData);
	
	    if ( erStat != 0 ) {
		    cout << "Error WinSock version initializaion #";
		    cout << WSAGetLastError();
		    return 1;
	    }
	    else
		    cout << "WinSock initialization is OK" << endl;
}