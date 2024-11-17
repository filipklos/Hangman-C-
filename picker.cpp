//plik ten składa się z 1 funkcji która zostanie uruchomiona przez plik main.cpp
#include <iostream>
#include "heading.h"
#include <fstream>
#include <string>
#include <random>
#include <vector>

using namespace std;

//funkcja ta otwiera plik i wybiera z bazy danych (plik words.txt) losowe słowo oraz kategorie jaką to słowo ma przypisaną, funkcja.
//funkcja ta modyfikuje tylko zmienne które pochodzą z pliku main.cpp a nie zwraca własnych 
void picker(wstring &Pickedword, string &Pickedcategory)
{
    // tworzą się wszystkie zmienne lokalne potrzebne do działania funkcji
    string line, word, category;
    bool secondWord = false;
    int lineCount = 0;
    vector<pair<string, string>> wordsList;
    
    //otwarcie pliku do odczytu
    ifstream words("words.txt");

    if (words.is_open())
    {
        //plik został otwarty i teraz pętla while będzie po kolei wczytywać dane z pliku (hasła i kategorie)
        //dane pobrane z pliku będą zapisywane w wektorze
        while (getline (words, line))
        {
            secondWord = false;
            word = "";
            category = "";
            for (char letter : line)
            {
                //w pliku hasło od kategori rozdzielone jest znakiem ';' dlatego dzięki temu program będzie wstanie bezproblemowo rozdzielić te słowa od siebie
                if (letter == ';')
                {
                    secondWord = true;
                } else
                {
                    if (secondWord)
                    {
                        category += letter;
                    } else
                    {
                        word += letter;
                    }
                    }
            }
            //dodawanie słów z danego wiersza do wektora oraz dodanie 1 do lineCount dzięki czemu program będzie wiedzieć ile plik ma wierszy
            wordsList.push_back({word, category});
            lineCount ++;
        }
        words.close();

        //generowanie liczby losowej z zakresu od [0 do liczby linii w pliku - 1]
        mt19937 gen(time(nullptr));

        uniform_int_distribution <int> dist(0, lineCount - 1);

        int randomNumber = dist(gen);

        // Wygenerowana liczba losowa sprawia, że zostają wybrane słowa z losowego wiersza z pliku, po czym funkcja kończy działanie.
        // Wartości te będą mogły zostać użyte dalej przez plik main.cpp.
        Pickedword = stringToWstring(wordsList[randomNumber].first);
        Pickedcategory = wordsList[randomNumber].second;
    } else
    {
        //otwarcie pliku się niepowiodło
        cerr << "Błąd odczytu z pliku" << endl;
    }
}