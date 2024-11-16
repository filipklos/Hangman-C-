#include <iostream>
#include <string>
#include "heading.h"
#include <cctype>

using namespace std;

void playerInserts(wstring& word, string& category, const int& mode)
{
    string wordTmp;
    wstring categoryTmp;
    bool isValid = false, error = false;
    while (!isValid)
    {
        if (mode == 2)
        {
            clearConsole();
            infoMode2();
        } else
        {
            clearConsole();
            infoMode3();
        }
        cout << "Hasło oraz kategoria mogą składać się wyłącznie z liter polskiego alfabetu" << endl;

        if (error) cout << endl << "W podanych wyrazach znalazły się nieprawidłowe dane, spróbuj ponownie" << endl << endl;

        cout << "Podaj proszę kategorię jakiej jakiej ma dotyczyć hasło: ";
        cin >> category;
        cout << "Proszę podaj hasło: ";
        cin >> wordTmp;

        word = stringToWstring(wordTmp);
        categoryTmp = stringToWstring(category);

        if (isWstringValid(word) && isWstringValid(categoryTmp))
        {
            category = wstringToString(categoryTmp);
            isValid = true;
        } else
        {
            error = true;
        }
    }
}