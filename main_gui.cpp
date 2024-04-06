#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

#include "main_input.cpp"
#include "classFile.cpp"
#include "classDate.cpp"
#include "Mtimes.cpp"
#include "emptyfiles.cpp"
#include "comparison.cpp"
//global variables

vector<File> v;
int month = 0;
string date;


string strcvt(const wchar_t* buffer, int len) {
    wstring wstr(buffer, len);
    return string(wstr.begin(), wstr.end());
}

void f1(){}
void f2(HWND hWnd){MessageBoxW(hWnd, L"File Doesnt Exist", L"Error", MB_OK);}
void f3(){}

//reference taken from  https://www.youtube.com/watch?v=8GCvZs55mEM&list=PLWzp0Bbyy_3i750dsUj7yq4JrPOIUR_NK
// https://www.thinkage.ca/gcos/expl/c/lib/wcstom.html
//https://learn.microsoft.com/en-us/cpp/text/how-to-convert-between-various-string-types?view=msvc-170#example-convert-from-wchar_t-
//https://www.ibm.com/docs/en/i/7.3?topic=functions-swprintf-format-write-wide-characters-buffer

void AddControls(HWND hWnd){
    CreateWindowW(L"static", L"Enter Input File Location", WS_VISIBLE | WS_CHILD         , 10 , 10, 200, 30, hWnd, NULL    , NULL, NULL);
    CreateWindowW(L"button", L"Input", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 220, 35, 100, 30, hWnd, (HMENU)1, NULL, NULL);
    CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 10, 35, 200, 30, hWnd, (HMENU)2, NULL, NULL);
    

    //CreateWindowW(L"button", L"Button 3", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, 10, 90, 100, 30, hWnd, (HMENU)4, NULL, NULL);
}


LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){
    switch(msg){
        case WM_CREATE:
            AddControls(hWnd);
            break;
        case WM_COMMAND:
        //even cases are for button commands and even cases are for taking input from user
            switch(LOWORD(wp)){
                case 1:
                    {
                        HWND hEdit = GetDlgItem(hWnd, 2);
                        int len = GetWindowTextLengthW(hEdit);
                        wchar_t* buffer = new wchar_t[len + 1];
                        GetWindowTextW(hEdit, buffer, len + 1);
                        string input = strcvt(buffer, len);
                        delete[] buffer;




                        //cout << input << " success\n";
                        int i = input_parser(v, input);
                        if(i == 0){
                            MessageBoxW(hWnd, L"Please enter valid .txt or .csv files", L"Error", MB_OK);
                        }
                        else if(i == 2){
                            MessageBoxW(hWnd, L"File Doesnt Exist", L"Error", MB_OK);
                        }
                        else{
                            //v is created, we can now call other functions :D

                            //removing old files:
                            CreateWindowW(L"static", L"Removing Old Files..", WS_VISIBLE | WS_CHILD | WS_BORDER            , 10 , 80, 200, 30, hWnd, NULL    , NULL, NULL);
                            CreateWindowW(L"static", L"Remove files older than (in months)", WS_VISIBLE | WS_CHILD         , 10 , 110, 200, 30, hWnd, NULL    , NULL, NULL);
                            CreateWindowW(L"button", L"Next", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON                        , 80 , 140, 100, 30, hWnd, (HMENU)4, NULL, NULL);
                            CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 10 , 140, 50, 30, hWnd, (HMENU)3, NULL, NULL);

                        }
                    }
                    break;

                case 4:
                {
                    //removing old files
                    
                    HWND hEdit = GetDlgItem(hWnd, 3);
                    int len = GetWindowTextLengthW(hEdit);
                    wchar_t* buffer = new wchar_t[len + 1];
                    GetWindowTextW(hEdit, buffer, len + 1);
                    string input = strcvt(buffer, len);
                    month = str_int(input);
                    delete[] buffer; 
                    CreateWindowW(L"static", L"Today's date:", WS_VISIBLE | WS_CHILD                               , 220 , 110, 200, 30, hWnd, NULL    , NULL, NULL);
                    CreateWindowW(L"button", L"Next", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON                        , 350 , 140, 100, 30, hWnd, (HMENU)6, NULL, NULL);
                    CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 220 , 140, 100, 30, hWnd, (HMENU)5, NULL, NULL);
                    break;

                }
                
                case 6:
                {
                    HWND hEdit = GetDlgItem(hWnd, 5);
                    int len = GetWindowTextLengthW(hEdit);
                    wchar_t* buffer = new wchar_t[len + 1];
                    GetWindowTextW(hEdit, buffer, len + 1);
                    date = strcvt(buffer, len);
                    delete[] buffer; 
                    int del_date = compare_month(v, month, date);
                    cout << endl << del_date << " file(s) have been removed succesfully :)\n\n";


                    //Less than m times opened
                    
                    CreateWindowW(L"static", L"Deleting unused/obsolete files:", WS_VISIBLE | WS_CHILD | WS_BORDER                    , 10 , 200, 300, 30, hWnd, NULL    , NULL, NULL);
                    CreateWindowW(L"static", L"Minimum number of times a file should have been opened", WS_VISIBLE | WS_CHILD         , 10 , 230, 300, 30, hWnd, NULL    , NULL, NULL);
                    CreateWindowW(L"button", L"Next", WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON                                           , 80 , 260, 100, 30, hWnd, (HMENU)8, NULL, NULL);
                    CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL                   , 10 , 260, 50 , 30, hWnd, (HMENU)7, NULL, NULL);

                }

                case 8:
                {
                    HWND hEdit = GetDlgItem(hWnd, 7);
                    int len = GetWindowTextLengthW(hEdit);
                    wchar_t* buffer = new wchar_t[len + 1];
                    GetWindowTextW(hEdit, buffer, len + 1);
                    string m_t = strcvt(buffer, len);
                    delete[] buffer; 
                    int m_times = str_int(m_t);
                    int c = lessThanMTimes(v, m_times);
                    cout << c << " file(s) have been removed succesfully :)\n\n";

                    //comparing files and removing duplicates and files with same data
                    CreateWindowW(L"static", L"Removing duplicates...", WS_VISIBLE | WS_CHILD | WS_BORDER                    , 10 , 300, 300, 30, hWnd, NULL    , NULL, NULL);
                    int ca = compareAndDelete(v);
                    cout << ca << " file(s) have been removed succesfully :)\n\n";

                    CreateWindowW(L"static", L"Finished.", WS_VISIBLE | WS_CHILD | WS_BORDER                    , 10 , 300, 350, 30, hWnd, NULL    , NULL, NULL);

                }
                    
                    

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

    CreateWindowW(L"myWindowClass", L"File Cleaner", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 500, 500, NULL, NULL, NULL, NULL);

    MSG msg = {0};

    while(GetMessage(&msg, NULL, NULL, NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
    
    //MessageBox(NULL, "qwe", "11", MB_OK);
    return 0;
}