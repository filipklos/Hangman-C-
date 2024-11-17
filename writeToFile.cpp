//plik odpowiedzialny za dopisanie do bazy danych nowego hasła i kategorii. uruchamiane przez plik main.cpp jeśli gracz wybrał tryb gry numer 3 i podał odpowiednie hasło oraz kategorię
#include <iostream>
#include <fstream>
#include <string>
#include "heading.h"

using namespace std;

//wskaźnik do zmiennych z pliku main.cpp (tutaj są one zapisane jako const ponieważ nie będą one zmieniane a tylko dopisane do pliku)
void writeToFile(const wstring& word, const string category)
{
    const string wordString = wstringToString(word); //użycie funkcji z pliku funcions.cpp do zamiany wstringa na stringa

    //otwarcie pliku w trybie dopisuwania
    ofstream words("words.txt", ios::app);


    if (words.is_open()) {
        //jeżeli udało się otworzyć plik to nasze wartości są do niedo dopisywane
        words << wordString << ";" << category << endl;
        words.close();
        cout << "Dane zostały zapisane do pliku." << endl;
    } else {
        //pliku nie udało się otworzyć wartości nie zostały zapisane
        cerr << "Nie udało się otworzyć pliku!" << endl;
    }
}