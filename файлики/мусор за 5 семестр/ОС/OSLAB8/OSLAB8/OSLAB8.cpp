#include "framework.h"
#include "OSLAB8.h"
#include <CommCtrl.h>
#include <windowsx.h>

//#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
//WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
//WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

HWND hDlg = NULL;
HWND hFindDlg = NULL; // ???

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//BOOL OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct);
//void OnDestroy(HWND hwnd);
//void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
INT_PTR CALLBACK Save(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
//BOOL Dialog_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
//void Dialog_OnClose(HWND hwnd);
//void Dialog_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine, _In_ int nCmdShow) {
   
    WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.hInstance = hInstance;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
    wcex.lpszClassName = TEXT("OS LAB 8");
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;

    if (0 == RegisterClassEx(&wcex)) {
            return -1;
    }

    HWND hWnd = CreateWindowEx(0, TEXT("OS LAB 8"), TEXT("Main Window"), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

    if (hWnd == NULL) {
        return -1;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_OSLAB8));

    // ------------------
    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    // ------------------

    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {

    case WM_CREATE: {
        CreateWindowEx(0, MONTHCAL_CLASS, TEXT("Календарь"), WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_NOTODAY,
            0, 0, 250, 250, hWnd, (HMENU)IDC_CAL, hInst, NULL);

        CreateWindowEx(0, TEXT("EDIT"), TEXT("Текст"), WS_BORDER | ES_AUTOHSCROLL | ES_LEFT | WS_CHILD | WS_VISIBLE,
            280, 0, 100, 20, hWnd, (HMENU)IDC_EDIT, hInst, NULL);

        CreateWindowEx(0, TEXT("LISTBOX"), TEXT("Список"), WS_BORDER | WS_CHILD | WS_VISIBLE,
            280, 80, 250, 250, hWnd, (HMENU)IDC_LIST, hInst, NULL);

        CreateWindowEx(0, UPDOWN_CLASS, TEXT("Вверх-вниз"), WS_BORDER | WS_CHILD | WS_VISIBLE,
            500, 0, 50, 50, hWnd, (HMENU)IDC_UPDOWN, hInst, NULL);

        return TRUE;
    }
    
    case WM_COMMAND: {
            int wmId = LOWORD(wParam);
            switch (wmId) {
            case ID_FILE_SAVE:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, Save);
                return TRUE;
            case ID_REPLACE:
                return TRUE;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
            break;
        }
    case WM_DESTROY: {
        PostQuitMessage(0);
        break;
    }

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//BOOL OnCreate(HWND hWnd, LPCREATESTRUCT lpCreateStruct) {
//
//    CreateWindowEx(0, MONTHCAL_CLASS, TEXT("Календарь"), WS_BORDER | WS_CHILD | WS_VISIBLE | MCS_NOTODAY,
//        0, 0, 250, 250, hWnd, (HMENU)IDC_CAL, lpCreateStruct->hInstance, NULL);
//
//    CreateWindowEx(0, TEXT("EDIT"), TEXT("Текст"), WS_BORDER | ES_AUTOHSCROLL | ES_LEFT | WS_CHILD | WS_VISIBLE,
//        280, 0, 100, 20, hWnd, (HMENU)IDC_EDIT, lpCreateStruct->hInstance, NULL);
//
//    CreateWindowEx(0, TEXT("LISTBOX"), TEXT("Список"), WS_BORDER | WS_CHILD | WS_VISIBLE,
//        280, 80, 250, 250, hWnd, (HMENU)IDC_LIST, lpCreateStruct->hInstance, NULL);
//
//    CreateWindowEx(0, UPDOWN_CLASS, TEXT("Вверх-вниз"), WS_BORDER | WS_CHILD | WS_VISIBLE,
//        500, 0, 50, 50, hWnd, (HMENU)IDC_UPDOWN, lpCreateStruct->hInstance, NULL);
//
//    return TRUE;
//}

//void OnDestroy(HWND hwnd) {
//    PostQuitMessage(0);
//}

//void OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) {
//    HINSTANCE hInstance = GetWindowInstance(hwnd);
//    switch (id) {
//    case ID_FILE_SAVE: {
//        int nDlgResult = DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DialogProc);
//        
//        /*if (IDOK == nDlgResult) {
//            SendMessage(hwnd, WM_SAVE, 0, 0);
//        }*/
//    } break;
//    case ID_REPLACE:
//        break;
//    }
//    
//}

INT_PTR CALLBACK Save(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_INITDIALOG: {
        //BOOL bRet = HANDLE_WM_INITDIALOG(hwndDlg, wParam, lParam, Dialog_OnInitDialog);
        //return SetDlgMsgResult(hwndDlg, uMsg, bRet);
        return TRUE;
    }
    /*case WM_CLOSE: {

        return TRUE;
    }*/
    case WM_COMMAND: {
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }

    return FALSE;
    }
}

//BOOL Dialog_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) {
//    return TRUE;
//}
//
//void Dialog_OnClose(HWND hwnd) {
//    if (hwnd == hDlg) {
//        DestroyWindow(hwnd);
//    }
//    else {
//        EndDialog(hwnd, IDCLOSE);
//    }
//}
//
//void Dialog_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) {
//    switch (id) {
//        case IDOK: {
//            /*int cch = GetDlgItemText(hwnd, IDC_EDIT1, szBuffer, _countof(szBuffer));
//            if (0 == cch) {
//                HWND hwndEdit = GetDlgItem(hwnd, IDC_EDIT1);
//                EDITBALLOONTIP ebt = { sizeof(EDITBALLOONTIP) };
//                ebt.pszTitle = L"SampleWin32";
//                ebt.pszText = L"Укажите название новой записи";
//                ebt.ttiIcon = TTI_WARNING;
//                Edit_ShowBalloonTip(hwndEdit, &ebt);
//            }*/
//            /*else*/ /*if (hwnd == hDlg) {
//                SetDlgItemText(hwnd, IDC_EDIT1, NULL);
//                SendMessage(GetParent(hwnd), WM_ADDITEM, 0, 0);
//            }*/
//            /*else */{
//                EndDialog(hwnd, IDOK);
//            }
//        } break;
//        case IDCANCEL: {
//            if (hwnd == hDlg) {
//                DestroyWindow(hwnd);
//            }
//            else {
//                EndDialog(hwnd, IDCANCEL);
//            }
//        } break;
//    }
//}

// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}
