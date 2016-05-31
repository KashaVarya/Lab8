#include<windows.h>
#include<iostream>
#include<ctype.h>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    //Polzovatel vvodit put k papke
    cout << "Vvedite put k papke: ";
    char adr[80];
    cin >> adr;

    //Poluchaem spisok faylov v ukazannoi papke
    WIN32_FIND_DATAA FindFileData;
    HANDLE hf;

   // hf=FindFirstFileA("c:\\test\\test2\\*", &FindFileData);
   // hf=FindFirstFileA("d:\\AFILE\\*", &FindFileData);

    hf=FindFirstFileA(adr, &FindFileData);  // ukazivaem put

    string s[10]; //massiv s nazvaniyami faylov v papke
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

    //vivodim metadannie
    string str1 = adr;
    str1.erase(str1.length()-1, 1);
    string str2;
    for(int i = 0; i < 2; i++)
    {
        str2 = str1 + s[2+i]; // put k faylam + nazvaniye faylov s massiva
        ifstream fin(str2, ios_base::in);
        if(!fin.is_open()) {
            cout << "\nFile don't open";
            return 0;
        }
        string str_for_audio; // stroka dlya zapisi
        getline(fin, str_for_audio);
        fin.close();

        int position1 = str_for_audio.find("TYER");
        string album = str_for_audio.substr(21, position1 - 21);
        cout << "Albom: " << album << endl;

        position1 += 11;
        int position2 = str_for_audio.find("TPE2");
        string god = str_for_audio.substr(position1, position2 - position1);
        cout << "God: " << god << endl;

        position1 = position2 + 11;
        position2 = str_for_audio.find("TIT2");
        string ispolnitel = str_for_audio.substr(position1, position2 - position1);
        cout << "Ispolnitel: " << ispolnitel << endl;

        position1 = position2 + 11;
        position2 += 11;
        while(!isspace(str_for_audio[position2])) position2++;
        string nazvaniye = str_for_audio.substr(position1, position2 - position1);
        cout << "Nazvaniye: " << nazvaniye << endl;

        //redaktiruem metadannie
        cout << "Xotite redaktirovat?(1- da, 0- net): ";
        int ans;
        cin >> ans;
        if(ans == 1) {
            cout << "Albom: ";
            cin >> album;
            position1 = str_for_audio.find("TYER");
            str_for_audio.replace(21, position1 - 21, album);

            cout << "God: ";
            cin >> god;
            position1 = str_for_audio.find("TYER") + 11;
            position2 = str_for_audio.find("TPE2");
            str_for_audio.replace(position1, position2 - position1, god);

            cout << "Ispolnitel: ";
            cin >> ispolnitel;
            position1 = str_for_audio.find("TPE2") + 11;
            position2 = str_for_audio.find("TIT2");
            str_for_audio.replace(position1, position2 - position1, ispolnitel);

            cout << "Nazvaniye: ";
            cin >> nazvaniye;
            position1 = str_for_audio.find("TIT2") + 11;
            position2 = str_for_audio.find("TIT2") + 11;
            while(!isspace(str_for_audio[position2])) position2++;
            str_for_audio.replace(position1, position2 - position1, nazvaniye);
        }
        ofstream fout(str2);
        fout << str_for_audio;
        fout.close();
    }
    system("pause");
    return 0;
}
