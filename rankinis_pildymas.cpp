#include "rankinis_pildymas.h"
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
#include "spausdinimas.h"
using namespace std;
using std::endl;
using std::setprecision;
using std::setw;
using std::left;


void rankinisPildymas() {
    cout << "Iveskite studetu skaiciu: ";
    int studentuSkaicius;
    cin >> studentuSkaicius;

    vector<studentas> grupeStudentu;
    grupeStudentu.reserve(studentuSkaicius);

    for (int i = 0; i < studentuSkaicius; i++) {
        float sum = 0, vid;
        studentas kint;

        cout << "Iveskite " << i + 1 << "-o studento varda ir pavarde: " << endl;
        cin >> kint.vard >> kint.pavard;


        int pazymiuSkaicius;
        cout << "Iveskite norima paz. skaiciu studentui" << " " << kint.vard << " " << kint.pavard << endl;
        cin >> pazymiuSkaicius;

        for (int i = 0; i < pazymiuSkaicius; i++) {
            cout << "Iveskite pazymi (1-10):";
            int pazimys;
            cin >> pazimys;
            while ((pazimys < 1) || (pazimys > 10)) {
                cout << "Neteisingas pazymys, iveskite dar karta" << endl;
                cin >> pazimys;
            }
            kint.nd.push_back(pazimys);
            sum += kint.nd[i];
        }
        cout << "Iveskite egzamino pazymi " << " " << kint.vard << " " << kint.pavard << endl;
        cin >> kint.egzam;

        vid = sum / pazymiuSkaicius;
        kint.gal = vid * 0.4 + 0.6 * kint.egzam;
        kint.med = mediana(kint.nd);
        grupeStudentu.push_back(kint);

    }
    cout << "\n";
    cout << left
        << setw(10) << "Vardas"
        << setw(10) << "Pavarde"
        << setw(12) << "Egzaminas"
        << setw(20) << "Galutinis (vid.)"
        << setw(15) << "Galutinis (med.)"
        << endl;
    cout << "-----------------------------------------------------------------" << endl;

    for (const auto& studentas : grupeStudentu) {
        printas(studentas);
    }
}