// v0.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
#include "spausdinimas.h"
#include "rankinis_pildymas.h"
#include "automatinis_generavimas.h"
using namespace std;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::setw;
using std::left;
using std::vector;

int main() {
    int automatinisGeneravomas = 0;
    cout << "Pasirinkite ar pazymius norite pildyti automatiskai (1), rankiniu budu (0), ar nuskaityti is failo (2):";
    cin >> automatinisGeneravomas;
    while ((automatinisGeneravomas != 1) && (automatinisGeneravomas != 0) && (automatinisGeneravomas != 2)) {
        cout << "Neteisingas pazymys, iveskite dar karta" << endl;
        cin >> automatinisGeneravomas;
    }
    vector<studentas> grupeStudentu;
    switch (automatinisGeneravomas) {
    case 1:
        pazymiuAutomatisPildymas();
        break;
    case 0:
        rankinisPildymas();
        break;
    case 2:
        read_from_file(grupeStudentu);
        spausdinti(grupeStudentu);
        system("pause");
        return 0;
    }
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
