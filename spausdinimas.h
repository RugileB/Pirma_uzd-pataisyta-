#pragma once
#include "strukt.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
using namespace std;

void printas(studentas kint) {
    cout << left
        << setw(10) << kint.vard
        << setw(10) << kint.pavard
        << setw(12) << kint.egzam
        << setw(20) << setprecision(3) << kint.gal
        << setw(15) << setprecision(3) << kint.med
        << endl;
    cout << "\n";
}

void spausdinti(vector<studentas> grupe) {
    std::ofstream output;
    output.open("kursiokai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n";
    for (int i = 0; i < grupe.size(); i++) {
        output << setw(20) << left << grupe[i].vard
            << setw(20) << left << grupe[i].pavard
            << setw(20) << left << grupe[i].gal
            << setprecision(3) << grupe[i].med << endl;
    }
    output << "\n\n";
}

void spausdinti(list<studentas> grupe) {
    std::ofstream output;
    output.open("kursiokai.txt");
    output << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(vid.)/"
        << left << "Galutinis(med.)\n";
    for (list<studentas>::iterator IT = grupe.begin(); IT != grupe.end(); IT++) {
        auto tempStudentas = (*IT);
        output << setw(20) << left << tempStudentas.vard
            << setw(20) << left << tempStudentas.pavard
            << setw(20) << left << tempStudentas.gal
            << setprecision(3) << tempStudentas.med << endl;
    }
    output << "\n\n";
}