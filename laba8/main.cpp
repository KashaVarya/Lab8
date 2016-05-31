#include<windows.h>
#include<iostream>
#include<ctype.h>
#include<string>
#include<fstream>
using namespace std;

int main()
{
    //Khokhlova
    //Polzovatel vvodit put k papke
    cout << "Vvedite put k papke: ";
    char adr[80];
    cin >> adr;

    //Sergeev
    //Poluchaem spisok faylov v ukazannoi papke
    WIN32_FIND_DATAA FindFileData;
    HANDLE hf;
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
    cout << s[2] << endl
         << s[3] << endl
         << s[4] << endl
         << s[5] << endl;

    string str1 = adr;
    str1.erase(str1.length()-1, 1);
    string str2;

    for(int n=2; n<6; n++) {
        if(n==4 || n==5)
        {
            str2 = str1 + s[n]; // put k faylam + nazvaniye faylov s massiva
            ifstream fin(str2, ios_base::in);
            if(!fin.is_open()) {
                cout << "\nFile don't open";
                return 0;
            }
            string str_for_audio; // stroka dlya zapisi
            getline(fin, str_for_audio);
            fin.close();

            //vivodim metadannie
            int position1 = str_for_audio.find("TYER");
            string album = str_for_audio.substr(21, position1 - 21);
            cout << "\nAlbom: " << album << endl;

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

            //Khokhlova
            //redaktiruem metadannie
            cout << "Xotite redaktirovat?(1- da, 0- net): ";
            int ans;
            cin >> ans;
            if(ans == 1) {
                cout << "\nAlbom: ";
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
                cout << "Izmeneniya vneseni!\n";
            }
            ofstream fout(str2);
            fout << str_for_audio;
            fout.close();
        }
        if(n==2 || n==3)
        {
            str2 = str1 + s[n]; // put k faylam + nazvaniye faylov s massiva
            ifstream fin(str2, ios_base::in);
            if(!fin.is_open()) {
                cout << "\nFile don't open";
                return 0;
            }
            string str_for_image; // stroka dlya zapisi
            getline(fin, str_for_image);
            fin.close();

            //vivodim metadannie
            string camera = str_for_image.substr(2164, 5);
            cout << "\nCamera: " << camera << endl;
            string model = str_for_image.substr(2170, 4);
            cout << "Model: " << model << endl;
            string prava = str_for_image.substr(2176, 10);
            cout << "Prava: " << prava << endl;

            //redaktiruem metadannie
            cout << "Xotite redaktirovat?(1- da, 0- net): ";
            int ans;
            cin >> ans;
            if(ans == 1) {
                cout << "\nCamera: ";
                cin >> camera;
                str_for_image.replace(2164, 5, camera);

                cout << "Model: ";
                cin >> model;
                str_for_image.replace(2170, 4, model);

                cout << "Prava: ";
                cin >> prava;
                str_for_image.replace(2176, 10, prava);
                cout << "Izmeneniya vneseni!\n";
            }
            ofstream fout(str2);
            fout << str_for_image;
            fout.close();
        }
    }
    system("pause");
    return 0;
}
