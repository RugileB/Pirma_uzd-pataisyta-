// v0.1(masyvas).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::setw;
using std::left;
using std::vector;


struct studentas {
    string vard, pavard;
    float nd[10]{};
    float egzam{};
    float gal{};
    float med{};
};


void pild(studentas& studento);
double mediana(float* nd);
void printas(studentas& studento);

int main()
{
    studentas studentai[10];
    int studentuSkaicius;
    cout << "Kiek bus studentu? (1-10) "; cin >> studentuSkaicius;

    if (studentuSkaicius < 1 || studentuSkaicius > 10) {
        cout << "Neteisingas ivestas skaicius";
        exit(EXIT_SUCCESS);
    }
    for (int i = 0; i < studentuSkaicius; i++)
        pild(studentai[i]);
    cout << "\n";
    cout << left
        << setw(10) << "Vardas"
        << setw(10) << "Pavarde"
        << setw(10) << "Egzaminas"
        << setw(20) << "Galutinis (vid.)"
        << setw(20) << "Galutinis (med.)"
        << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (int i = 0; i < studentuSkaicius; i++)
        printas(studentai[i]);
}

void pild(studentas& studento) {
    int namuDarbuSkaicius;
    cout << "Iveskite studento varda ir pavarde: "; cin >> studento.vard >> studento.pavard;
    cout << "Kiek namu darbu bus? (1-10)"; cin >> namuDarbuSkaicius;
    float sum = 0, vid;
    for (int i = 0; i < namuDarbuSkaicius; i++) {
        cout << "Iveskite pazymi (1-10):";
        cin >> studento.nd[i];
        if ((studento.nd[i] < 1) || (studento.nd[i] > 10)) {
            cout << "Neteisingas pazymys, iveskite dar karta";
            exit(EXIT_SUCCESS);
        }
        sum += studento.nd[i];
    }
    vid = sum / namuDarbuSkaicius;
    studento.med = (float)mediana(studento.nd);

    cout << "Iveskite egzamino pazymi:"; cin >> studento.egzam;
    studento.gal = (float)(vid * 0.4 + studento.egzam * 0.6);
}

double mediana(float* nd) {
    int masyvoIlgis = sizeof(nd) / sizeof(nd[0]);
    sort(nd, nd + masyvoIlgis);

    if (masyvoIlgis % 2 != 0)
        return (double)nd[masyvoIlgis / 2];

    return (double)(nd[(masyvoIlgis - 1) / 2] + nd[masyvoIlgis / 2]) / 2.0;
}

void printas(studentas& studento) {
    cout << left
        << setw(10) << studento.vard
        << setw(10) << studento.pavard
        << setw(10) << studento.egzam
        << setw(20) << setprecision(3) << studento.gal
        << setw(20) << setprecision(3) << studento.med
        << endl;
    cout << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
