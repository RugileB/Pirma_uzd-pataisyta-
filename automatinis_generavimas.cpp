#include "automatinis_generavimas.h"
#include "mediana.h"
#include "spausdinimas.h"
#include <iomanip>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::setw;


void pazymiuAutomatisPildymas() {
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
        int pazymiuSkaicius; // paz sk.
        cout << "Iveskite norima paz. skaiciu studentui" << " " << kint.vard << " " << kint.pavard << endl;
        cin >> pazymiuSkaicius;

        kint.egzam = random_sk();
        cout << "Random egzamino pazymys: " << kint.egzam << endl;

        srand(time(0));
        for (int x = 0; x < pazymiuSkaicius; x++) {
            kint.nd.push_back(random_sk());
            cout << "Random nd pazymys: " << kint.nd[x] << endl;
            sum += kint.nd[x];
        }

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

int random_sk() //sugeneruoja bet koki skaiciu nuo 1 iki 10
{
    return rand() % 10 + 1;
}