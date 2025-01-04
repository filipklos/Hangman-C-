// Plik nagłówkowy, dzięki któremu mogę używać funkcji z jednych plików w innych plikach
#pragma once
#include <string>

using namespace std;

// Wszystkie funkcje używane przez różne pliki, ich wyjaśnienia znajdują się w odpowiednich plikach

// Największe funkcje zawierające własne pliki, nazwane tak, jak nazywa się funkcja, tylko z rozszerzeniem .cpp
void picker(wstring &word, string &category); // Funkcja wybierająca hasło i kategorię
void draw(int level); // Funkcja rysująca szubienicę w zależności od poziomu
void game(const wstring& word, const string& category); // Funkcja zarządzająca główną grą
void writeToFile(const wstring& word, const string category); // Funkcja zapisująca hasło do pliku
void playerInserts(wstring& word, string& category, const int& mode); // Funkcja umożliwiająca graczowi wstawienie hasła i kategorii

// Funkcje z pliku functions.cpp
void setConsoleGreen(); // Funkcja zmieniająca kolor konsoli na zielony
void clearConsole(); // Funkcja czyszcząca konsolę
void slowCout(const string& text); // Funkcja wyświetlająca tekst znak po znaku
void infoStart(); // Funkcja wyświetlająca informacje o rozpoczęciu gry
void infoMode2(); // Funkcja wyświetlająca informacje o trybie 2
void infoMode3(); // Funkcja wyświetlająca informacje o trybie 3
wstring hide(const wstring text); // Funkcja zamieniająca litery na znaki '_'
int lenWithOutSpaces(const wstring text); // Funkcja licząca długość wstringa bez spacji
wstring insertLetter(const wstring text, wstring hidden, const wchar_t letter); // Funkcja wstawiająca literę w odpowiednie miejsce w haśle
bool isSpecialChar(const wchar_t character); // Funkcja sprawdzająca, czy znak jest specjalnym polskim znakiem
bool isInVector(const vector<wchar_t>& vec, const wchar_t letter); // Funkcja sprawdzająca, czy znak znajduje się w wektorze
wstring stringToWstring(const string& text); // Funkcja konwertująca string na wstring
string wstringToString(const wstring& text); // Funkcja konwertująca wstring na string
bool isWstringValid(wstring& text); // Funkcja sprawdzająca, czy wstring jest poprawny
bool isWchar_tValid(wchar_t& letter); // Funkcja sprawdzająca, czy wchar_t jest poprawny