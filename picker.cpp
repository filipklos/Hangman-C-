// Plik ten składa się z jednej funkcji, która zostanie uruchomiona przez plik main.cpp
#include <iostream>
#include "heading.h"
#include <fstream>
#include <string>
#include <random>
#include <vector>

using namespace std;

// Funkcja ta otwiera plik i wybiera z bazy danych (plik words.txt) losowe słowo oraz kategorię,
// którą to słowo ma przypisaną. Funkcja ta modyfikuje tylko zmienne, które pochodzą z pliku main.cpp
// a nie zwraca własnych wartości.
void picker(wstring &Pickedword, string &Pickedcategory)
{
    // Tworzenie zmiennych lokalnych potrzebnych do działania funkcji
    string line, word, category;
    bool secondWord = false;
    vector<pair<string, string>> wordsList;

    // Otwarcie pliku do odczytu
    ifstream words("words.txt");

    if (words.is_open())
    {
        // Plik został otwarty i teraz pętla while będzie po kolei wczytywać dane z pliku (hasła i kategorie)
        // Dane pobrane z pliku będą zapisywane w wektorze
        while (getline(words, line))
        {
            secondWord = false;
            word = "";
            category = "";
            for (char letter : line)
            {
                // W pliku hasło od kategorii rozdzielone jest znakiem ';' dlatego program będzie w stanie
                // rozdzielić te elementy i przypisać je do odpowiednich zmiennych
                if (letter == ';')
                {
                    secondWord = true;
                }
                else
                {
                    if (secondWord)
                    {
                        category += letter;
                    }
                    else
                    {
                        word += letter;
                    }
                }
            }
            // Dodawanie słów z danego wiersza do wektora oraz zwiększanie lineCount,
            // aby program wiedział, ile linii znajduje się w pliku
            wordsList.push_back({word, category});
        }
        words.close();

        // Generowanie liczby losowej z zakresu od 0 do liczby linii w pliku - 1
        mt19937 gen(time(nullptr));
        uniform_int_distribution<int> dist(0, wordsList.size() - 1);
        int randomNumber = dist(gen);

        // Wygenerowana liczba losowa wybiera słowa z losowego wiersza w pliku,
        // po czym funkcja kończy działanie. Wartości te będą mogły zostać użyte w main.cpp.
        Pickedword = stringToWstring(wordsList[randomNumber].first);
        Pickedcategory = wordsList[randomNumber].second;
    }
    else
    {
        // Otwarcie pliku się nie powiodło
        cerr << "Błąd odczytu z pliku" << endl;
    }
}