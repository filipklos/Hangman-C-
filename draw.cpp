//plik rysujący odpowiedni poziom szubienicy od 0 do 6, plik jest uruchamiany orzez funkcję game wewnątrz pliku game.cpp
#include <iostream>

using namespace std;

void draw(int level)
{
    switch(level)
    {
        case 0:
        {
            cout << R"(
 +---+
 |   |
     |
     |
     |
     |
=======
)";
            break;
        }
        case 1:
        {
            cout << R"(
 +---+
 |   |
 O   |
     |
     |
     |
=======
)";
            break;
        }
        case 2:
        {
            cout << R"(
 +---+
 |   |
 O   |
 |   |
     |
     |
=======
)";
            break;
        }
        case 3:
        {
            cout << R"(
 +---+
 |   |
 O   |
/|   |
     |
     |
=======
)";
            break;
        }
        case 4:
        {
            cout << R"(
 +---+
 |   |
 O   |
/|\  |
     |
     |
=======
)";
            break;
        }
        case 5:
        {
            cout << R"(
 +---+
 |   |
 O   |
/|\  |
/    |
     |
=======
)";
            break;
        }
        case 6:
        {
            cout << R"(
 +---+
 |   |
 O   |
/|\  |
/ \  |
     |
=======
)";
            break;
        }
    }
}