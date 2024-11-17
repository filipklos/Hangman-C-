//plik nagłówkowy dzięki któremu mogę użwać funkcji z jednych plików w drugich plikach
#pragma once
#include <string>

using namespace std;


//wszystkie funkcje używane przez rózne pliki ich wyjaśnienia znajdują się w odpowiednich plikach 

//największe funkcję zawierające własne pliki nazwane tak jak nazywa się funkcja tylko z rozszerzeniem .cpp
void picker(wstring &word, string &category);
void draw(int level);
void game(const wstring& word, const string& category);
void writeToFile(const wstring& word, const string category);
void playerInserts(wstring& word, string& category, const int& mode);

//funkcje z pliku funcions.cpp
void clearConsole();
void infoStart();
void infoMode2();
void infoMode3();
wstring hide(const wstring text);
int lenWithOutSpaces(const wstring text);
wstring insertLetter(const wstring text, wstring hidden, const wchar_t letter);
bool isSpecialChar(const wchar_t character);
bool isInVector(const vector<wchar_t>& vec, const wchar_t letter);
wstring stringToWstring(const string& text);
string wstringToString(const wstring& text);
bool isWstringValid(wstring& text);
bool isWchar_tValid(wchar_t& letter);