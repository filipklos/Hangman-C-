#include <iostream>
#include <string>
#include "heading.h"
using namespace std;

int main()
{
    int mode;
    wstring word;
    string category;

    clearConsole();
    infoStart();
    cin >> mode;

    switch (mode)
    {
        case 1:
        {   
            picker(word, category);
            game(word, category);
            break;
        }
        case 2:
        {
            playerInserts(word, category, mode);
            game(word, category);
            break;
        }
        case 3:
        {
            playerInserts(word, category, mode);
            writeToFile(word, category);
            break;           
        }
        default:
        {
            cerr << "Wybrano nieodpowiednią opcję, program kończy działanie" << endl;
            break;
        }
    }
    return 0;
}