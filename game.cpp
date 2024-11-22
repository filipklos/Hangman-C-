//plik uruchamiany przez main.cpp będący tą główną grą w wisielca
#include <iostream>
#include "heading.h"
#include <string>
#include <cwctype>
#include <vector>

using namespace std;

//funkcja ta modyfikuje tylko zmienne które pochodzą z pliku main.cpp a nie zwraca własnych 
void game(const wstring& word, const string& category)
{
    //teraz aby wcout poprawnie się wyświetlało używam imbue
    wcout.imbue(locale(""));

    //zmienne lokalne potrzebne do działania funkcji
    int level = 0, guessed, sumGuessed = 0;
    string letter;
    wchar_t letterWchar;
    vector<wchar_t> correctAns; //wektor z poprawnyli literami jakie podał gracz
    vector<wchar_t> incorrectAns; //wektor z błędnymi literami jakie podał gracz
    wstring password = hide(word); //użycie własnej funckji hide z pliku funcions.cpp, która zmienia hasło na ciąg znaków '_' oraz zachowuje spacje
    const int SumLetters = lenWithOutSpaces(word); // //użycie własnej funckji hide z pliku funcions.cpp, zwraca długość zmiennej word bez doliczania spacji
            
    //pętla działająca do momętu zwycięstwa lub porażki
    while (level < 6 && sumGuessed != SumLetters)
    {
        bool isValid = false;

        //pętla działająca do momętu aż gracz poda prawidłowe dane       
        while (!isValid)
        {
            //czyszczenie konsoli i wyświetlanie kategori oraz zasłoniętego hasła z odsłoniętymi tylko zgadniętymi literami
            clearConsole();

            slowCout("Kategoria: ");
            slowCout(category);
            cout<< endl;

            slowCout("Hasło: ");
            slowCout(wstringToString(password));
            cout << endl;
            
            //użycie włanej funkcji która w zależności od poziomu gry rysuje szubienice
            draw(level);

            //wyświetlanie liter które gracz już podał a okazały się niepoprawne
            wstring incorrects;
            slowCout("litery niepoprawne: ");
            for (wchar_t i : incorrectAns)
            {
                incorrects += i;
                incorrects += L' ';
            }
            slowCout(wstringToString(incorrects));
            cout << endl;

            //gracz podaje nową literę
            slowCout("Podaj literę: ");
            cin >> letter;
            letterWchar = stringToWstring(letter)[0]; //własna funkcja z pliku funcions.cpp zmieniająca string na wstring

            //warunek używający funkcji z pliku funcions.cpp sprawdzający czy podana litera jest prawidłowa (walidacja danych wejściowych)
            if (isWchar_tValid(letterWchar) && !(isInVector(correctAns, letterWchar) || isInVector(incorrectAns, letterWchar)))
            {
                //jeżli litera jest poprawna to następuje sprawdzenie czy i jeśli tak to ile razy ta liczba występuje w naszym haśle
                isValid = true;
                guessed = count(word.begin(), word.end(), letterWchar);
                if (guessed == 0)
                {
                    //jeśli nie występuje to poziom się zwiększa oraz litera zostaje dodana do wektora z błędnymi odpowiedziami
                    level ++;
                    incorrectAns.push_back(letterWchar);
                } else
                {
                    //jeśli występuje to ilość odgadniętych liter jest sumowana
                    sumGuessed += guessed;
                    password = insertLetter(word, password, letterWchar); //uruchomienie funkcji z funcions.cpp która zmienia '_' w naszm ukrutym haśle ta tą poprawną literę
                    correctAns.push_back(letterWchar); //dadanie tej poprawnej liczby do wektora
                }
            }
        }
    }
    //decyzja o tym czy gracz wygrał czy przegrał
    clearConsole();
    if (level == 6)
    {
        //gracz przegrał
        slowCout("Przegrana!");
        cout << endl;
        draw(level);
        slowCout("Poprawne hasło to: ");
        slowCout(wstringToString(word));
        cout << endl;
    } else
    {
        //gracz wygrał
        slowCout("Gratulacje Udało ci się wygrać!");
        cout << endl;
        draw(level);
        slowCout("odgadłeś hasło: ");
        cout << "odgadłeś hasło: ";
        slowCout(wstringToString(word));
        cout << endl;
    }
}