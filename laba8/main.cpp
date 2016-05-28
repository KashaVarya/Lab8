#include<windows.h>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hf;
    hf=FindFirstFile(L"c:\\test\\test2\\*", &FindFileData);    // вывод названий файлов по указаному пути
   // hf=FindFirstFile(L"d:\\AFILE\\*", &FindFileData);

    wstring s[5];
    int i=0;


    if (hf!=INVALID_HANDLE_VALUE){
        do{
            //wcout << FindFileData.cFileName << "\n";
            s[i] = FindFileData.cFileName;
            i++;
        }
        while (FindNextFile(hf,&FindFileData)!=0);
        FindClose(hf);
    }
    wcout << s[0] << endl << s[1] << endl;
    wcout << s[2] << endl << s[3] << endl;
    return 0;
}
