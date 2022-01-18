#pragma once
#include <vector>
#include "struktura.h"
#include "mediana.h"
#include <iterator>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iostream>
using std::vector;
using std::ifstream;
using namespace std;

unsigned int countWordsInString(string const& str);
void read_from_file(vector<studentas>& grupe, bool pagalMediana);
void readFromFile2(std::vector<studentas>& grupe, int kiek);

unsigned int countWordsInString(string const& str) {
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
}

void read_from_file(vector<studentas>& grupe, bool pagalMediana)
{
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
    catch (int e)
    {
        cout << "Neteisingai ivestas failo pavadinimas " << e << std::endl;

    }
}

void readFromFile2(std::vector<studentas>& grupe, int kiek) {
    int student_counter = 0;
    std::ifstream file("Studentai_" + to_string(kiek) + ".txt");
    if (file.is_open()) {
        auto start = std::chrono::high_resolution_clock::now();
        std::string line;
        while (std::getline(file, line)) {
            grupe.resize(grupe.size() + 1);
            file >> grupe.at(student_counter).vard;
            file >> grupe.at(student_counter).pavard;
            file >> grupe.at(student_counter).gal;
            student_counter++;
        }
        file.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Failo su " + to_string(kiek) + " studentu/-ais nuskaitymas uztruko: " << diff.count() << " s\n";
    }
}