#include <iostream>
#include <cstdlib>
#include <string>
#include <locale>
#include <vector>
#include <codecvt>
#include <cwctype>



using namespace std;

void clearConsole()
{
#ifdef _WIN32
    system("cls");  // Dla Windows
#else
    system("clear");  // Dla Linux, macOS
#endif
}

void infoStart()
{
    cout << "Widaj w grze wisielec" << endl;
    cout << "Wybierz odpowiedni tryb gry wpisując z klawiatury odpowiednią komendę" << endl;
    cout << "Jeśli grasz w pojedynkę zmierzysz się z hasłem wygenerowanym przez komputer i postarasz się na nie odpowiedzieć w tym celu wpisz: 1" << endl;
    cout << "Jeśli grasz z drugą osobą to 1 osoba poda hasło a drgupa postara się je odgadnąć. Aby wejść w ten tryb gry wpisz: 2" << endl;
    cout << "Jeśli chcesz dodać nowe hasło do bazy danych wybierz: 3" << endl;
}

void infoMode2()
{
    cout << "W tym trybie samodzielnie utworzysz utworzysz własne hasło oraz własną kategorię." << endl;
    cout << "Następnie drugi gracz będzie musiał odgadnąć twoje hasło" << endl;
}
void infoMode3()
{
    cout << "W tym trybie samodzielnie utworzysz utworzysz własne hasło oraz własną kategorię." << endl;
    cout << "Następnie zostaną one dodane do bazy danych" << endl;
}

wstring hide(const wstring text)
{   
    wstring hided;
    for (wchar_t i : text) hided += (i != L' ') ? L'_' : L' ';
    return hided;
}

int lenWithOutSpaces(const wstring text)
{
    int spaces = 0;
    for (wchar_t i : text) if (i == L' ') spaces ++;
    return text.size() - spaces;
}

wstring insertLetter(const wstring text, wstring hidden, const wchar_t letter)
{
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == letter) hidden[i] = letter;
    }
    return hidden;
}

bool isSpecialChar(const wchar_t character)
{
    wchar_t specialChar[9] = {L'ą', L'ć', L'ę', L'ł', L'ń', L'ó', L'ś', L'ź', L'ż'};
    for (wchar_t i : specialChar)
    {
        if (character == i) return true;
    }
    return false;
}

bool isInVector(const vector<wchar_t>& vec, const wchar_t letter)
{
    for (wchar_t i : vec)
    {
        if (letter == i) return true;
    }
    return false;
}

wstring stringToWstring(const string& text)
{
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(text);
}

string wstringToString(const wstring& text)
{
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(text);
}

bool isWchar_tValid(wchar_t& letter)
{
    locale::global(locale(""));
    letter = tolower(letter);
    if ((letter >= 97 && letter <= 122) || isSpecialChar(letter)) return true;
    return false;
}

bool isWstringValid(wstring& text)
{
    for (wchar_t& i : text)
    {
        if (!isWchar_tValid(i)) return false;
    }
    return true;
}