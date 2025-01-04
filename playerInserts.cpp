// Plik używany przez main.cpp, służy do tego, by gracz mógł podać swoje własne hasło oraz kategorię
#include <iostream>
#include <string>
#include "heading.h"

using namespace std;

// Funkcja pobiera wskaźniki do zmiennych z pliku main.cpp i je modyfikuje
void playerInserts(wstring& word, string& category, const int& mode)
{
    // Zmienne potrzebne do działania funkcji
    string wordTmp;
    wstring categoryTmp;
    bool isValid = false, error = false;

    // Sprawdzanie, czy gracz podał odpowiednie dane
    while (!isValid)
    {
        // W zależności od trybu gry (1 lub 2-osobowy), wyświetlany jest odpowiedni komunikat
        if (mode == 2)
        {
            // Gracz jest w trybie gry 2-osobowej
            clearConsole();
            infoMode2();
        } 
        else
        {
            // Gracz chce zapisać nowe hasło do bazy danych
            clearConsole();
            infoMode3();
        }

        // Informacja dla gracza
        slowCout("Hasło oraz kategoria mogą składać się wyłącznie z liter polskiego alfabetu");
        cout << endl;

        // Jeśli wystąpił błąd walidacji przy poprzednich danych, wyświetlany jest komunikat o błędzie
        if (error)
        {
            cout << endl;
            slowCout("W podanych wyrazach znalazły się nieprawidłowe dane, spróbuj ponownie");
            cout << endl << endl;
        }
        else
        {
            // Czyszczenie strumienia wejściowego przed odczytem (tylko za pierwszym uruchomieniem pętli)
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Gracz podaje kategorię oraz hasło
        slowCout("Podaj proszę kategorię, jakiej ma dotyczyć hasło: ");
        getline(cin, category);
        slowCout("Proszę podaj hasło: ");
        getline(cin, wordTmp);

        // Konwersja z string na wstring za pomocą funkcji z pliku functions.cpp
        word = stringToWstring(wordTmp);
        categoryTmp = stringToWstring(category);

        // Walidacja danych przy pomocy funkcji z pliku functions.cpp
        if (isWstringValid(word) && isWstringValid(categoryTmp))
        {
            // Walidacja zakończona sukcesem, zapisujemy kategorię jako string i kończymy pętlę
            category = wstringToString(categoryTmp); // Konwersja z wstring na string
            isValid = true;
        }
        else
        {
            // Błąd walidacji, pętla uruchomi się ponownie
            error = true;
        }
    }
}