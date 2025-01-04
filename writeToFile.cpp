// Plik odpowiedzialny za dopisanie do bazy danych nowego hasła i kategorii.
// Uruchamiane przez plik main.cpp, jeśli gracz wybrał tryb gry numer 3
// i podał odpowiednie hasło oraz kategorię.
#include <iostream>
#include <fstream>
#include <string>
#include "heading.h"

using namespace std;

// Wskaźnik do zmiennych z pliku main.cpp (tutaj są one zapisane jako const,
// ponieważ nie będą one zmieniane, a jedynie dopisane do pliku).
void writeToFile(const wstring& word, const string category)
{
    const string wordString = wstringToString(word); // Użycie funkcji z pliku functions.cpp do zamiany wstringa na stringa.

    // Otwarcie pliku w trybie dopisania.
    ofstream words("words.txt", ios::app);

    if (words.is_open()) {
        // Jeżeli udało się otworzyć plik, nasze wartości są dopisywane.
        words << wordString << ";" << category << endl;
        words.close();
        slowCout("Dane zostały zapisane do pliku.");
        cout << endl;
    } else {
        // Pliku nie udało się otworzyć, wartości nie zostały zapisane.
        cerr << "Nie udało się otworzyć pliku!" << endl;
    }
}