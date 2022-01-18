// v0.5(naujas).cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "strukt.h"
#include "mediana.h"
#include "failo_skait.h"
#include "spausdinimas.h"
//#include "rankinisPildymas.h"
//#include "automatinis_generavimas.h"
#include "failo_generavimas.h"
#include "rusiavim.h"
#include <vector>
#include <list>

using namespace std;
using std::list;

int main() {
    //    int automatinisGeneravimas = 0;
    //    cout
    //            << "Pasirinkite ar pazymius norite pildyti automatiskai (1), rankiniu budu (0), nuskaityti is failo (2) ar generuoti faila automatiskai (3):vector vs list (4) ";
    //    cin >> automatinisGeneravimas;
    //    bool pagalMediana;
    //    cout << "Pasirinkite kokiu budu bus skaiciuojamas galutinis pazymis: pagal mediana (1), pagal vidurki (0): ";
    //    cin >> pagalMediana;
    //    while ((automatinisGeneravimas != 1) && (automatinisGeneravimas != 0) && (automatinisGeneravimas != 2) &&
    //           (automatinisGeneravimas != 3) && (automatinisGeneravimas != 4)) {
    //        cout << "Neteisingas pazymys, iveskite dar karta" << endl;
    //        cin >> automatinisGeneravimas;
    //    }
    //
    //    vector<studentas> grupeStudentu;
    //    switch (automatinisGeneravimas) {
    //        case 1:
    //            pazymiuAutomatisPildymas(grupeStudentu, pagalMediana);
    //            break;
    //        case 0:
    //            cout << "Iveskite studetu skaiciu: ";
    //            int studentuSkaicius;
    //            cin >> studentuSkaicius;
    //            grupeStudentu.reserve(studentuSkaicius);
    //            rankinisPildymas(grupeStudentu, pagalMediana);
    //            break;
    //        case 2:
    //            readFromFile2(grupeStudentu, pagalMediana);
    //            spausdinti(grupeStudentu);
    //        case 3:
    //            generavimas(1000, pagalMediana);
    //            readFromFile2(grupeStudentu, 1000);
    //        case 4:
    for (int i = 1000; i < 10000001; i *= 10) {
                     generavimas(i, false);
        vector<studentas> grupeStudentuVector;
        list<studentas> grupeStudentuList;
        readFromFile2(grupeStudentuVector, i);
        rusiavimasIGtrupes(grupeStudentuVector);
        readFromFile2(grupeStudentuList, i);
        rusiavimasIGtrupes(grupeStudentuList);
    }
    return -1;
    //    }
    //    rusiavimas(grupeStudentu);
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
