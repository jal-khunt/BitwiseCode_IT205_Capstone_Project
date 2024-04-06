#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

#include "main_input.cpp"
#include "classFile.cpp"
#include "Mtimes.cpp"
#include "emptyfiles.cpp"
#include "comparison.cpp"

void f1(){}
void f2(){}
void f3(){}

//reference taken from  https://www.youtube.com/watch?v=8GCvZs55mEM&list=PLWzp0Bbyy_3i750dsUj7yq4JrPOIUR_NK

void AddControls(HWND hWnd){
    // Create button 1
    CreateWindowW(L"button", L"Button 1", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 520, 10, 100, 30, hWnd, (HMENU)1, NULL, NULL);

    CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 10, 10, 500, 30, hWnd, (HMENU)2, NULL, NULL);
    
    CreateWindowW(L"button", L"Button 2", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, 50, 100, 30, hWnd, (HMENU)3, NULL, NULL);
    
    CreateWindowW(L"button", L"Button 3", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, 90, 100, 30, hWnd, (HMENU)4, NULL, NULL);
}


LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    switch(msg){
        case WM_CREATE:
            AddControls(hWnd);
            break;
        case WM_COMMAND:
            switch(LOWORD(wp)){
                case 1:
                    {
                        HWND hEdit = GetDlgItem(hWnd, 2);
                        int len = GetWindowTextLengthW(hEdit);
                        wchar_t* buffer = new wchar_t[len + 1];
                        cout << *buffer << endl;
                        GetWindowTextW(hEdit, buffer, len + 1);
                        MessageBoxW(hWnd, buffer, L"Input", MB_OK);
                        delete[] buffer;
                    }
                    break;
                case 2:
                    f2();
                    break;
                case 3:
                    f3();
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
    return 0;
}


//"main" function 
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){
    WNDCLASSW wc = {0};

    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";
    wc.lpfnWndProc = WindowProcedure;

    if(!RegisterClassW(&wc)) return -1;

    CreateWindowW(L"myWindowClass", L"My window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while(GetMessage(&msg, NULL, NULL, NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
    
    //MessageBox(NULL, "qwe", "11", MB_OK);
    return 0;
}