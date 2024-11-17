//plik używany przez main.cpp służy do tego by gracz mógł podać swoje własne hasło oraz kategorię
#include <iostream>
#include <string>
#include "heading.h"
#include <cctype>

using namespace std;
//funkcja pobiera wskaźniki do zmiennych z pliku main.cpp i je modyfikuje
void playerInserts(wstring& word, string& category, const int& mode)
{
    //zmienne potrzebne do działania funkcji
    string wordTmp;
    wstring categoryTmp;
    bool isValid = false, error = false;

    //sprawdzanie czy gracz podał odpowiednie dane
    while (!isValid)
    {
        //sprawdzanie w jakim trybie jest gracz i w zaleności od tego jest wyświetlany odpowieni komunikat
        if (mode == 2)
        {
            //gracz jest w trybie gry 2-osobowej
            clearConsole();
            infoMode2();
        } else
        {
            //gracz tylko chce zapisać nowe hasło do bazy danych
            clearConsole();
            infoMode3();
        }
        cout << "Hasło oraz kategoria mogą składać się wyłącznie z liter polskiego alfabetu" << endl;

        //sprawdzenie czy gracz podał dane które okazały się nie prawdziwe (dla drugiego i każdego kolejnego uruchomienia pętli), dla pierwszego uruchomienia pętli wykonanie instrukcji else
        if (error)
        {
            cout << endl << "W podanych wyrazach znalazły się nieprawidłowe dane, spróbuj ponownie" << endl << endl;
        } else
        {
            //Czyszczenie strumienia wejściowego przed odczytem (tylko za 1 uruchomieniem)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        //gracz podaje hasło oraz jego kategorię
        cout << "Podaj proszę kategorię jakiej jakiej ma dotyczyć hasło: ";
        getline(cin, category);
        cout << "Proszę podaj hasło: ";
        getline(cin, wordTmp);

        //użycie funkcji z pliku funcions.cpp do zmiany stringa na wstring
        word = stringToWstring(wordTmp);
        categoryTmp = stringToWstring(category);

        //walidacja danych przy pomocy funkcji z pliku funcions.cpp
        if (isWstringValid(word) && isWstringValid(categoryTmp))
        {
            //walidacja udana funkcja kończy działanie
            category = wstringToString(categoryTmp); //użycie funkcji z pliku funcions.cpp do zmiany wstringa na string
            isValid = true;
        } else
        {
            //błąd walidacji pętla uruchomi się jeszcze raz
            error = true;
        }
    }
}