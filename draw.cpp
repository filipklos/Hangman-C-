//plik rysujący odpowiedni poziom szubienicy od 0 do 6, plik jest uruchamiany orzez funkcję game wewnątrz pliku game.cpp
#include <iostream>
#include "heading.h"

using namespace std;

void draw(int level)
{
    switch(level)
    {
        case 0:
        {
            slowCout(R"(
 +---+
 |   |
     |
     |
     |
     |
=======
)");
            break;
        }
        case 1:
        {
            slowCout(R"(
 +---+
 |   |
 O   |
     |
     |
     |
=======
)");
            break;
        }
        case 2:
        {
            slowCout(R"(
 +---+
 |   |
 O   |
 |   |
     |
     |
=======
)");
            break;
        }
        case 3:
        {
            slowCout(R"(
 +---+
 |   |
 O   |
/|   |
     |
     |
=======
)");
            break;
        }
        case 4:
        {
            slowCout(R"(
 +---+
 |   |
 O   |
/|\  |
     |
     |
=======
)");
            break;
        }
        case 5:
        {
            slowCout(R"(
 +---+
 |   |
 O   |
/|\  |
/    |
     |
=======
)");
            break;
        }
        case 6:
        {
            slowCout(R"(
 +---+
 |   |
 O   |
/|\  |
/ \  |
     |
=======
)");
            break;
        }
    }
}