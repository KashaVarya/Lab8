#include<windows.h>
#include<iostream>

#include<string>
#include<fstream>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    //������������ ������ ���� � �����
    cout << "������� ���� � �����: ";
    char adr[80];
    cin >> adr;   //d:\\AFILE\\* (��� ����)

    //�������� ������ ������ � ��������� �����
    WIN32_FIND_DATAA FindFileData;
    HANDLE hf;

   // hf=FindFirstFileA("c:\\test\\test2\\*", &FindFileData);
    hf=FindFirstFileA("d:\\AFILE\\*", &FindFileData);

    //hf=FindFirstFileA(adr, &FindFileData);  // ��������� ����

    string s[10]; //������ � ���������� ������ � �����
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

    string str1;
    ifstream fin;
    fin.open("H:\\Programing\\otcheti\\GDiK\\Lab8\\Lab8\\Audio\\Imagine Dragons - Radioactive.mp3");
    if(!fin.is_open())
        cout << "Ne otkriolo";
    fin >> str1;
    cout << str1;

    fin.close();


    return 0;
}
