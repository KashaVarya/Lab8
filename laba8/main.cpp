#include<windows.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    hf=FindFirstFile(L"c:\\test\\test2\\*", &FindFileData);    // вывод названий файлов по указаному пути
    if (hf!=INVALID_HANDLE_VALUE){
        do{
            wcout << FindFileData.cFileName << "\n";
        }
        while (FindNextFile(hf,&FindFileData)!=0);
        FindClose(hf);
    }
    return 0;
}
