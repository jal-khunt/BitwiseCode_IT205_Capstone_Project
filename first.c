#include <windows.h>

#include <stdio.h>

int main(void)

{

HANDLE hFile1;

FILETIME ftCreate;

SYSTEMTIME stUTC, stLocal;

hFile1 = CreateFileW(L"D:\\DAIICT\\SEM 1\\CALCULUS\\project\\first.txt", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);


if (hFile1 == INVALID_HANDLE_VALUE)

{

printf("Could not open file, error %lu\n", GetLastError());

return -1;

}

if (!GetFileTime(hFile1, &ftCreate, NULL, NULL))

{

printf("Something wrong!\n");

return FALSE;

}

FileTimeToSystemTime(&ftCreate, &stUTC);

printf("UTC System Time format:\n");

printf("Created on: %02d/%02d/%d %02d:%02d\n", stUTC.wDay, stUTC.wMonth, stUTC.wYear, stUTC.wHour, stUTC.wMinute);

getchar();

return 0;

}