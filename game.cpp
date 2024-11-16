#include <iostream>
#include "heading.h"
#include <string>
#include <cwctype>
#include <locale>
#include <vector>

using namespace std;

void game(const wstring& word, const string& category)
{
    wcout.imbue(locale(""));
    locale::global(locale(""));

    int level = 0, guessed, sumGuessed = 0;
    string letter;
    wchar_t letterWchar;
    vector<wchar_t> correctAns;
    vector<wchar_t> incorrectAns;
    wstring password = hide(word);
    const int SumLetters = lenWithOutSpaces(word);
    wcout << word << endl;
    cout << category << endl;
            
    while (level < 6 && sumGuessed != SumLetters)
    {
        bool isValid = false;
                
        while (!isValid)
        {
            clearConsole();
            cout << "Kategoria: " << category << endl;
            wcout << L"Hasło: " << password << endl;

            draw(level);
        
            cout << "litery niepoprawne: ";
            for (wchar_t i : incorrectAns) wcout << i << L' ';
            cout << endl;

            cout << "Podaj literę: ";
            cin >> letter;
            letterWchar = stringToWstring(letter)[0];

            if (isWchar_tValid(letterWchar) && !(isInVector(correctAns, letterWchar) || isInVector(incorrectAns, letterWchar)))
            {
                isValid = true;
                guessed = count(word.begin(), word.end(), letterWchar);
                if (guessed == 0)
                {
                    level ++;
                    incorrectAns.push_back(letterWchar);
                } else
                {
                    sumGuessed += guessed;
                    password = insertLetter(word, password, letterWchar);
                    correctAns.push_back(letterWchar);
                }
            }
        }
    }
    clearConsole();
    if (level == 6)
    {
        cout << "Przegrana!" << endl;
        draw(level);
        cout << "Poprawne hasło to: ";
        wcout << word << endl;
    } else
    {
        cout << "Gratulacje Udało ci się wygrać!" << endl;
        draw(level);
        cout << "odgadłeś hasło: ";
        wcout << word << endl;
    }
}