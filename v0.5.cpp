// v0.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <chrono>
#include <list>

using std::string;
using std::list;
using namespace std;
using std::endl;
using std::to_string;
using std::setw;
using std::left;
using std::ifstream;


struct studentas {
    string vard, pavard;
    list<int> paz = { 0 };
    int egzam;
    float gal = 0;
};

int generate_random() {
    return rand() % 10 + 1;
}

studentas get(list<studentas> _list, int _i) {
    list<studentas>::iterator it = _list.begin();
    for (int i = 0; i < _i; i++) {
        ++it;
    }
    return *it;
}

list<int> auto_marks(int how_many_marks) {
    list<int> skaiciai;
    for (int i = 0; i < how_many_marks; i++) {
        skaiciai.push_back(generate_random());
    }
    return skaiciai;
}

float count_gal(list<int> skaiciai) {
    studentas grupe;
    grupe.gal = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * generate_random();
    return grupe.gal;
}


void generavimas(int studentuSkaicius) {
    auto start = std::chrono::high_resolution_clock::now();

    std::ofstream out_data("../Studentai_" + to_string(studentuSkaicius) + ".txt");
    list<int> skaiciai;
    out_data << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(vid.)"
        << endl;

    for (int s = 1; s <= studentuSkaicius; s++) {
        skaiciai = auto_marks(5);
        out_data << setw(20) << "Vardas" + to_string(s) <<
            setw(20) << "Pavarde" + to_string(s) <<
            setw(18) << count_gal(skaiciai) << endl;;
        skaiciai.clear();
    }
    out_data.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failas su " << studentuSkaicius << " studentu kurimas uztruko: " << diff.count() << " s\n";

}

void readFromFile(std::list<studentas>& list, int kiek) {
    int student_counter = 0;
    std::ifstream file("../Studentai_" + to_string(kiek) + ".txt");
    if (file.is_open()) {
        auto start = std::chrono::high_resolution_clock::now();
        std::string line;
        while (std::getline(file, line)) {
            studentas studentas;
            file >> studentas.vard;
            file >> studentas.pavard;
            file >> studentas.gal;
            student_counter++;
            list.push_back(studentas);
        }
        file.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Failo su " + to_string(kiek) + " studentu/-ais nuskaitymas uztruko: " << diff.count() << " s\n";
    }
}


int main() {
    int kiek = 1000;
    for (int i = 0; i < 5; ++i) {
        generavimas(kiek);
        list<studentas> studentai;
        readFromFile(studentai, kiek);
        list<studentas> protingi;
        list<studentas> vargsiukai;

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < studentai.size(); i++) {
            float paz = 5.00;
            auto tempStudentas = get(studentai, i);
            if (tempStudentas.gal < paz) {
                vargsiukai.push_back(tempStudentas);
            }
        }
        for (int i = 0; i < studentai.size(); i++) {
            float paz = 5.00;
            auto tempStudentas = get(studentai, i);
            if (tempStudentas.gal >= paz) {
                protingi.push_back(tempStudentas);
            }
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << "Failo rusiavimas su " + to_string(kiek) + " studentais i dvi grupes uztruko : " << diff.count()
            << " s\n";

        // Vargsiukai
        std::ofstream vargs_failas("../vargsiukai_" + to_string(kiek) + ".txt");
        auto start1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < vargsiukai.size(); i++) {
            auto tempStudentas = get(studentai, i);
            vargs_failas << tempStudentas.vard << setw(20) << tempStudentas.pavard << setw(18)
                << tempStudentas.gal << endl;
        }
        vargs_failas.close();
        auto end1 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end1 - start1;
        cout << "Failo isvedimas su " + to_string(kiek) + " studentais  i vargsiukus uztruko : " << diff1.count()
            << " s\n";

        // protingieji
        std::ofstream prot_failas("../protingi_" + to_string(kiek) + ".txt");
        auto start2 = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < protingi.size(); j++) {
            auto tempStudentas = get(studentai, j);
            prot_failas << tempStudentas.vard << setw(20) << tempStudentas.pavard << setw(18)
                << tempStudentas.gal << endl;
        }
        prot_failas.close();
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end2 - start2;
        cout << "Failo isvedimas su " + to_string(kiek) + " studentais  i protingus uztruko : " << diff2.count()
            << " s\n";
        kiek *= 10;
        system("pause");
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
