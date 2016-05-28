#include<windows.h>
#include<iostream>

#include<string>

#include <string>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    //Пользователь вводит путь к папке
    cout << "Введите путь к папке: ";
    char adr[80];
    cin >> adr;   //d:\\AFILE\\*

    //Получаем список файлов в указанной папке
    WIN32_FIND_DATAA FindFileData;
    HANDLE hf;

    hf=FindFirstFile(L"c:\\test\\test2\\*", &FindFileData);
   // hf=FindFirstFile(L"d:\\AFILE\\*", &FindFileData);

    hf=FindFirstFileA(adr, &FindFileData);  // указываем путь
>>>>>>> 3505427d46638811b5e9a9655632d60da22e8cd0

    string s[10]; //массив с названиями файлов в папке
    int i=0;
    if (hf!=INVALID_HANDLE_VALUE){
        do{
            s[i] = FindFileData.cFileName;
            i++;
        }
        while (FindNextFileA(hf,&FindFileData)!=0);
        FindClose(hf);
    }
    cout << s[2] << endl << s[3] << endl;



    return 0;
}
