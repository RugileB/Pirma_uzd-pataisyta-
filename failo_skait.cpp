#include <vector>
#include "struktura.h"
#include "failo_skait.h"
#include "mediana.h"
#include <fstream>
#include <iostream>
#include <sstream>

using std::ifstream;
using std::cout;

unsigned int countWordsInString(string const& str) {
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
}

void read_from_file(vector<studentas>& grupe)
{
    int iteracija = 0;
    int temp;
    int pazymiuSkaicius;
    ifstream fileRead("C:\\Users\\Envy\\Desktop\\Objektinio uzduotys\\studentai10000.txt.txt");
    string buffer;

    try {
        if (!fileRead.is_open())
            throw 0;
        getline(fileRead >> std::ws, buffer);
        pazymiuSkaicius = countWordsInString(buffer) - 3;
        while (true) {
            grupe.resize(grupe.size() + 1);
            fileRead >> grupe.at(iteracija).vard;
            if (fileRead.eof()) {
                grupe.pop_back();
                break;
            }
            fileRead >> grupe.at(iteracija).pavard;
            for (int i = 0; i < pazymiuSkaicius; i++) {
                fileRead >> temp;
                grupe.at(iteracija).nd.push_back(temp);
            }
            fileRead >> grupe.at(iteracija).egzam;
            grupe.at(iteracija).gal = grupe.at(iteracija).gal / pazymiuSkaicius;
            grupe.at(iteracija).gal = grupe.at(iteracija).gal * 0.4 + 0.6 * grupe.at(iteracija).egzam;
            grupe.at(iteracija).med = mediana(grupe.at(iteracija).nd);
            iteracija++;
        }

    }
    catch (int e)
    {
        cout << "Neteisingai ivestas failo pavadinimas " << e << std::endl;

    }
}