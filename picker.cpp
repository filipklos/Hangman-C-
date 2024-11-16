#include <iostream>
#include "heading.h"
#include <fstream>
#include <string>
#include <random>
#include <vector>

using namespace std;

void picker(wstring &Pickedword, string &Pickedcategory)
{
    string line, word, category;
    bool secondWord = false;
    int lineCount = 0;
    vector<pair<string, string>> wordsList;
    
    ifstream words("words.txt");

    if (words.is_open())
    {
        while (getline (words, line))
        {
            secondWord = false;
            word = "";
            category = "";
            for (char letter : line)
            {
                if (letter == ';')
                {
                    secondWord = true;
                } else
                {
                    if (secondWord)
                    {
                        category += letter;
                    } else
                    {
                        word += letter;
                    }
                    }
            }
            wordsList.push_back({word, category});
            lineCount ++;
        }
        words.close();

        mt19937 gen(time(nullptr));

        uniform_int_distribution <int> dist(0, lineCount - 1);

        int randomNumber = dist(gen);

        Pickedword = stringToWstring(wordsList[randomNumber].first);
        Pickedcategory = wordsList[randomNumber].second;
    } else
    {
        cerr << "Błąd odczytu z pliku" << endl;
    }
}