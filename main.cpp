// Plik główny spinający grę w całość
#include <iostream>
#include <string>
#include "heading.h"
using namespace std;

int main()
{
    int mode;
    wstring word;
    string category, ending;

    do
    {
        // Czyszczenie konsoli, zmiana koloru tekstu na zielony i wyświetlanie informacji dla gracza
        clearConsole();
        setConsoleGreen();
        infoStart();

        // Gracz wybiera tryb gry
        cin >> mode;
        clearConsole();

        switch (mode)
        {
            case 1:
            {   
                // Tryb jednoosobowy: losowanie słowa i kategorii
                picker(word, category);
                // Uruchomienie gry w wisielca, gracz walczy o zwycięstwo 
                game(word, category);
                break;
            }
            case 2:
            {   
                // Gracz wybrał tryb 2-osobowy. Przy użyciu funkcji playerInserts, 1 gracz wymyśla hasło, na które odpowiada drugi gracz
                playerInserts(word, category, mode);
                // Uruchomienie gry w wisielca, gracz walczy o zwycięstwo 
                game(word, category);
                break;
            }
            case 3:
            {
                // Gracz wpisuje swoje hasło i kategorię, ale gra się nie rozpoczyna. Te informacje są dodawane do bazy danych,
                // dzięki czemu komputer będzie mógł w przyszłości wylosować te hasła
                playerInserts(word, category, mode);
                writeToFile(word, category);
                break;           
            }
            default:
            {
                // Gracz nie wybrał poprawnej opcji
                slowCout("Wybrano nieodpowiednią opcję.");
                cout << endl;
                cin.clear(); // usuwa flagę błędu z cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignoruje wszystko do końca linii (usuna znaki z buforu)
                break;
            }
        }
        cout << endl;
        slowCout("Jeśli chcesz kontynuować grę wciśnij na klawiaturze T lub t, natomiast jeśli chcesz aby program zakończył działanie wybierz jaki kolwiek inny przycisk: ");
        cin >> ending;

    } while(ending == "T" || ending == "t"); // Gracz kontynuuje grę tylko, jeśli wpisze 'T' lub 't'
    return 0;
}