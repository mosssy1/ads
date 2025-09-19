#include <fstream>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
/* 16. Придумать систему шифрации  текста.  Символы  с  кодами
1-31,243-255 не менять,  т.к. они могут играть роль служебных.
Написать программу шифрации-дешифрации текстового  файла. Шифр
не должен быть основан на однозначной замене  каждого  символа
другим по всему тексту (8).
Комиссарова Арина ПС-21*/

using namespace std;
void Crypt(ofstream& fileOut, ifstream& fileIn, int  key, int ch) {
    while ((ch = fileIn.get()) != EOF) {
        if ((ch > 31 && ch < 243) || ch > 255) {
            ch += key;
        }
        fileOut.put(ch);
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    string fileNameIn, fileNameOut, fileNameOutUncrypt;
    int status;

    cout << "Введите имя входного файла" << endl;
    cin >> fileNameIn;
    fileNameIn += ".txt";

    cout << "Введите имя выходного файла" << endl;
    cin >> fileNameOut;
    fileNameOut += ".txt";

    ifstream fileIn(fileNameIn);
    ofstream fileOut(fileNameOut);
    if (!fileIn.is_open())
    {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    cout << "Введите 1, чтобы зашифровать текст. Введите 2, чтобы расшифровать текст. " << endl;
    cin >> status;
    int ch = 0;
    if (status == 1){
        Crypt(fileOut, fileIn, 5, ch);
    }
    else if (status == 2){
        Crypt(fileOut, fileIn, -5, ch);
    }
    else {
        cout << "Введён неверный статус" << endl;
    }
    fileOut.flush();
    fileOut.close();

    return 0;
}
