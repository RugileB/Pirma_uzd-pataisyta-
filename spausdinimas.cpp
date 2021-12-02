#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <time.h> 
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "struktura.h"
#include "mediana.h"
#include "failo_skait.h"
using namespace std;
using std::endl;
using std::setprecision;
using std::setw;
using std::left;


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