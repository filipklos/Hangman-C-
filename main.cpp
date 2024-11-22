// Plik główny spinający grę w całość
#include <iostream>
#include <string>
#include "heading.h"
using namespace std;

int main()
{
    int mode;
    wstring word;
    string category;

    //konsola się czyści, zmienia kolor tekstu na zielony i wyświetla informacje dla gracza
    clearConsole();
    setConsoleGreen();
    infoStart();

    //gracz wybiera tryb gry
    cin >> mode;

    switch (mode)
    {
        case 1:
        {   
            //gracz wybrał tryb 1-osobowy. przy użyciu funkcji picker dla gracza zostanie przydzielone losowe słowo i jego kategoria z bazy danych
            picker(word, category);
            //gra w wisielca się uruchamia i gracz walczy o zwycięstwo 
            game(word, category);
            break;
        }
        case 2:
        {   
            //gracz wybrał tryb 2-osobowy. przy użyciu funkcji playerInserts 1 gracz sam wymyśla hasło na które odpowiada drugi z graczy
            playerInserts(word, category, mode);
            //gra w wisielca się uruchamia i gracz walczy o zwycięstwo 
            game(word, category);
            break;
        }
        case 3:
        {
            //tutaj gracz wpisuje swoje hasło i kategorię ale gra się nie rozpoczyna tylko informacje te zostają dodane do bazy danych dzięki czemu w przyszłych rozgrywach komputer będzie mógł wylosować te hasła
            playerInserts(word, category, mode);
            writeToFile(word, category);
            break;           
        }
        default:
        {
            //gracz nie wybrał kategori
            cerr << "Wybrano nieodpowiednią opcję, program kończy działanie" << endl;
            break;
        }
    }
    return 0;
}