#include <iostream>
#include <fstream>
#include <string>
#include "heading.h"

using namespace std;

void writeToFile(const wstring& word, const string category)
{
    const string wordString = wstringToString(word);

    ofstream words("words.txt", ios::app);

    if (words.is_open()) {
        words << wordString << ";" << category << endl;
        words.close();
        cout << "Dane zostały zapisane do pliku." << endl;
    } else {
        cerr << "Nie udało się otworzyć pliku!" << endl;
    }
}