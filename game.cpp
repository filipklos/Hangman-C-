// Plik uruchamiany przez main.cpp, będący główną grą w wisielca
#include <iostream>
#include "heading.h"
#include <string>
#include <vector>

using namespace std;

// Funkcja ta modyfikuje tylko zmienne, które pochodzą z pliku main.cpp, a nie zwraca własnych 
void game(const wstring& word, const string& category)
{
    // Zmienne lokalne potrzebne do działania funkcji
    int level = 0, guessed, sumGuessed = 0;
    string letter;
    wchar_t letterWchar;
    vector<wchar_t> correctAns; // Wektor z poprawnymi literami, które podał gracz
    vector<wchar_t> incorrectAns; // Wektor z błędnymi literami, które podał gracz
    wstring password = hide(word); // Użycie funkcji hide z pliku functions.cpp, która zmienia hasło na ciąg znaków '_' oraz zachowuje spacje
    const int SumLetters = lenWithOutSpaces(word); // Użycie funkcji lenWithOutSpaces z pliku functions.cpp, zwraca długość zmiennej word bez liczenia spacji
            
    // Pętla działająca do momentu zwycięstwa lub porażki
    while (level < 6 && sumGuessed != SumLetters)
    {
        bool isValid = false;

        // Pętla działająca do momentu, aż gracz poda prawidłowe dane       
        while (!isValid)
        {
            // Czyszczenie konsoli i wyświetlanie kategorii oraz zasłoniętego hasła z odsłoniętymi tylko zgadniętymi literami
            clearConsole();

            slowCout("Kategoria: ");
            slowCout(category);
            cout<< endl;

            slowCout("Hasło: ");
            slowCout(wstringToString(password));
            cout << endl;
            
            // Użycie funkcji, która w zależności od poziomu gry rysuje szubienicę
            draw(level);

            // Wyświetlanie liter, które gracz już podał, a okazały się niepoprawne
            wstring incorrects;
            slowCout("Litery niepoprawne: ");
            for (wchar_t i : incorrectAns)
            {
                incorrects += i;
                incorrects += L' ';
            }
            slowCout(wstringToString(incorrects));
            cout << endl;

            // Gracz podaje nową literę
            slowCout("Podaj literę: ");
            cin >> letter;
            letterWchar = stringToWstring(letter)[0]; // Własna funkcja z pliku functions.cpp zmieniająca string na wstring

            // Warunek używający funkcji z pliku functions.cpp sprawdzający, czy podana litera jest prawidłowa (walidacja danych wejściowych)
            if (isWchar_tValid(letterWchar) && !(isInVector(correctAns, letterWchar) || isInVector(incorrectAns, letterWchar)))
            {
                // Jeśli litera jest poprawna, to następuje sprawdzenie, czy i jeśli tak, to ile razy ta liczba występuje w naszym haśle
                isValid = true;
                guessed = count(word.begin(), word.end(), letterWchar);
                if (guessed == 0)
                {
                    // Jeśli nie występuje, to poziom się zwiększa oraz litera zostaje dodana do wektora z błędnymi odpowiedziami
                    level ++;
                    incorrectAns.push_back(letterWchar);
                } else
                {
                    // Jeśli występuje, to ilość odgadniętych liter jest sumowana
                    sumGuessed += guessed;
                    password = insertLetter(word, password, letterWchar); // Uruchomienie funkcji z functions.cpp, która zmienia '_' w ukrytym haśle na tę poprawną literę
                    correctAns.push_back(letterWchar); // Dodanie tej poprawnej litery do wektora
                }
            }
        }
    }
    // Decyzja o tym, czy gracz wygrał, czy przegrał
    clearConsole();
    if (level == 6)
    {
        // Gracz przegrał
        slowCout("Przegrana!");
        cout << endl;
        draw(level);
        slowCout("Poprawne hasło to: ");
        slowCout(wstringToString(word));
        cout << endl;
    } else
    {
        // Gracz wygrał
        slowCout("Gratulacje! Udało ci się wygrać!");
        cout << endl;
        draw(level);
        slowCout("Odgadłeś hasło: ");
        slowCout(wstringToString(word));
        cout << endl;
    }
}