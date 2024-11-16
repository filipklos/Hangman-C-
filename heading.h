#pragma once
#include <string>

using namespace std;

void picker(wstring &word, string &category);
void draw(int level);
void clearConsole();
void infoStart();
void infoMode2();
void infoMode3();
wstring hide(const wstring text);
int lenWithOutSpaces(const wstring text);
wstring insertLetter(const wstring text, wstring hidden, const wchar_t letter);
bool isSpecialChar(const wchar_t character);
bool isInVector(const vector<wchar_t>& vec, const wchar_t letter);
void game(const wstring& word, const string& category);
wstring stringToWstring(const string& text);
string wstringToString(const wstring& text);
void playerInserts(wstring& word, string& category, const int& mode);
bool isWstringValid(wstring& text);
bool isWchar_tValid(wchar_t& letter);
void writeToFile(const wstring& word, const string category);