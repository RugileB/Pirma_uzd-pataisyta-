#pragma once
#include <vector>
#include "strukt.h"
#include "mediana.h"
#include <iterator>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>
#include <list>

using std::vector;
using std::list;
using std::ifstream;
using namespace std;

unsigned int countWordsInString(string const& str) {
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
}

void read_from_file(vector<studentas>& grupe, bool pagalMediana) {
    int iteracija = 0;
    int temp;
    int pazymiuSkaicius;
    ifstream fileRead("studentai10000.txt");
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
            grupe.at(iteracija).med = mediana(grupe.at(iteracija).nd);
            if (pagalMediana)
                grupe.at(iteracija).gal = grupe.at(iteracija).med * 0.4 + 0.6 * grupe.at(iteracija).egzam;
            else
                grupe.at(iteracija).gal = grupe.at(iteracija).gal * 0.4 + 0.6 * grupe.at(iteracija).egzam;

            iteracija++;
        }

    }
    catch (int e) {
        cout << "Neteisingai ivestas failo pavadinimas " << e << std::endl;

    }
}

void readFromFile2(std::vector<studentas>& grupe, int kiek) {
    int line = 0;
    std::stringstream strStream;
    ifstream nustatymai("Studentai_" + to_string(kiek) + ".txt");
    nustatymai.ignore(10, '\n');
    strStream << nustatymai.rdbuf();
    auto start = std::chrono::high_resolution_clock::now();
    while (line < kiek) {
        grupe.resize(grupe.size() + 1);
        strStream >> grupe.at(line).vard;
        strStream >> grupe.at(line).pavard;
        strStream >> grupe.at(line).gal;
        line++;
    }

    nustatymai.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo su " + to_string(kiek) + " studentu/-ais nuskaitymas uztruko naudojant vector: " << diff.count()
        << " s\n";
}

void readFromFile2(std::list<studentas>& list, int kiek) {
    int line = 0;
    std::stringstream strStream;
    ifstream settigns("Studentai_" + to_string(kiek) + ".txt");
    settigns.ignore(10, '\n');
    strStream << settigns.rdbuf();
    auto start = std::chrono::high_resolution_clock::now();
    while (line < kiek) {
        studentas studentas;
        strStream >> studentas.vard;
        strStream >> studentas.pavard;
        strStream >> studentas.gal;
        list.push_back(studentas);
        line++;
    }

    settigns.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo su " + to_string(kiek) + " studentu/-ais settigns uztruko naudojant list: " << diff.count()
        << " s\n";
}
