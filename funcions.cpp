//plik z wieloma funkcjami używanymi w najróżniejszych miejscach w programie
#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <vector>
#include <codecvt>
#include <cwctype>



using namespace std;

//funkcja czyszcząca konsolę, funkcja storzona tak aby program mógł zadziałać na róznych systemach operacyjnych
void clearConsole()
{
#ifdef _WIN32
    system("cls");  // Dla Windows
#else
    system("clear");  // Dla Linux, macOS
#endif
}

//funkcja wyświetlająca informacje pojawiające się na początku uruchomineia programu
void infoStart()
{
    cout << "Widaj w grze wisielec" << endl;
    cout << "Wybierz odpowiedni tryb gry wpisując z klawiatury odpowiednią komendę" << endl;
    cout << "Jeśli grasz w pojedynkę zmierzysz się z hasłem wygenerowanym przez komputer i postarasz się na nie odpowiedzieć w tym celu wpisz: 1" << endl;
    cout << "Jeśli grasz z drugą osobą to 1 osoba poda hasło a drgupa postara się je odgadnąć. Aby wejść w ten tryb gry wpisz: 2" << endl;
    cout << "Jeśli chcesz dodać nowe hasło do bazy danych wybierz: 3" << endl;
}

//funkcja wyświetlająca informacje podczas włączeniu trybu drugiego gry
void infoMode2()
{
    cout << "W tym trybie samodzielnie utworzysz utworzysz własne hasło oraz własną kategorię." << endl;
    cout << "Następnie drugi gracz będzie musiał odgadnąć twoje hasło" << endl;
}

//funkcja wyświetlająca informacje podczas włączeniu trybu trzeciego gry
void infoMode3()
{
    cout << "W tym trybie samodzielnie utworzysz utworzysz własne hasło oraz własną kategorię." << endl;
    cout << "Następnie zostaną one dodane do bazy danych" << endl;
}

//funkcja zmieniająca litery na znaki '_' w haśle składającym się z liter oraz spacji
wstring hide(const wstring text)
{   
    wstring hided;
    for (wchar_t i : text) hided += (i != L' ') ? L'_' : L' ';
    return hided;
}

//funkcja licząca długość wstringa z pominięciem ilości spacji
int lenWithOutSpaces(const wstring text)
{
    int spaces = 0;
    for (wchar_t i : text) if (i == L' ') spaces ++;
    return text.size() - spaces;
}

//funkcja podstawiająca pod już ukryte hasło literę, wstawiając ją w odpowiednie dla niej miejsca
wstring insertLetter(const wstring text, wstring hidden, const wchar_t letter)
{
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == letter) hidden[i] = letter;
    }
    return hidden;
}

//funkcja sprawdzająca czy dany znak jest znakiem specjalnym z polskiego alfabetu 
bool isSpecialChar(const wchar_t character)
{
    wchar_t specialChar[9] = {L'ą', L'ć', L'ę', L'ł', L'ń', L'ó', L'ś', L'ź', L'ż'};
    for (wchar_t i : specialChar)
    {
        if (character == i) return true;
    }
    return false;
}

//funkcja spawdzająca czy znak letter znajduje się wewnątrz wektora
bool isInVector(const vector<wchar_t>& vec, const wchar_t letter)
{
    for (wchar_t i : vec)
    {
        if (letter == i) return true;
    }
    return false;
}

//funkcja konwertująca sting na wstring
wstring stringToWstring(const string& text)
{
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(text);
}

//funkcja konwertująca wsting na string
string wstringToString(const wstring& text)
{
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(text);
}

//funkcja sprawdzącza czy dany znak jest poprawny i może zostać użyty przez program w haśle lub do utworzenia hasła
bool isWchar_tValid(wchar_t& letter)
{
    locale::global(locale("")); //dla działania tolower dla polskich znaków
    letter = tolower(letter); //jeśli pojawiła się wielka litera to zmienianie ją na małą literę
    //sprawdzanie czy to litera, spacja albo znak specjalny 
    if ((letter >= 97 && letter <= 122) || letter == L' ' || isSpecialChar(letter)) return true;
    return false;
}

//funkcja sprawdzącza czy dany wstring jest poprawny i może zostać użyty przez program w haśle lub do utworzenia hasła
bool isWstringValid(wstring& text)
{
    //sprawdzenie czy dlugość tego wstringa bez liczenia spacji jest mnijesza od 2
    if (lenWithOutSpaces(text) < 2) return false;
    //iterowanie po wstringu i sprawdzanie poprawności każdego ze znaków osobno przez funkcję isWchar_tValid()
    for (wchar_t& i : text)
    {
        if (!isWchar_tValid(i)) return false;
    }
    return true;
}