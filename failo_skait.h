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

void readFromFile2(std::vector<studentas>& grupe, int kiek) {
    int line = 0;
    std::stringstream strStream;
    ifstream nustatymai("Studentai_" + to_string(kiek) + ".txt");
    nustatymai.ignore(10, '\n');
    strStream << nustatymai.rdbuf();
   // auto start = std::chrono::high_resolution_clock::now();
    while (line < kiek) {
        grupe.resize(grupe.size() + 1);
        strStream >> grupe.at(line).vard;
        strStream >> grupe.at(line).pavard;
        strStream >> grupe.at(line).gal;
        line++;
    }

    nustatymai.close();

    //auto end = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> diff = end - start;
   // cout << "Failo su " + to_string(kiek) + " studentu/-ais nuskaitymas uztruko naudojant vector: " << diff.count()
     //   << " s\n";
}

void readFromFile2(std::list<studentas>& list, int kiek) {
    int line = 0;
    std::stringstream strStream;
    ifstream settigns("Studentai_" + to_string(kiek) + ".txt");
    settigns.ignore(10, '\n');
    strStream << settigns.rdbuf();
    //auto start = std::chrono::high_resolution_clock::now();
    while (line < kiek) {
        studentas studentas;
        strStream >> studentas.vard;
        strStream >> studentas.pavard;
        strStream >> studentas.gal;
        list.push_back(studentas);
        line++;
    }

    settigns.close();
    //auto end = std::chrono::high_resolution_clock::now();
   // std::chrono::duration<double> diff = end - start;
    //cout << "Failo su " + to_string(kiek) + " studentu/-ais nuskaitymas uztruko naudojant list: " << diff.count()
     //   << " s\n";
}