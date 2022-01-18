#pragma once
#include "strukt.h"
#include "mediana.h"
#include <numeric>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <fstream>
using namespace std;



int generate_random() {
    return rand() % 10 + 1;
}

vector<float> auto_marks(int how_many_marks) {
    vector<float> skaiciai;
    for (int i = 0; i < how_many_marks; i++) {
        skaiciai.push_back(generate_random());
    }
    return skaiciai;
}

float count_gal(vector<float> skaiciai, bool pagalMediana) {
    studentas grupe;
    grupe.med = mediana(skaiciai);
    if (pagalMediana) {
        grupe.gal = 0.4 * grupe.med + 0.6 * generate_random();
    }
    grupe.gal = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * generate_random();
    return grupe.gal;
}

void generavimas(int studentuSkaicius, bool pagalMediana) {
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream out_data("Studentai_" + to_string(studentuSkaicius) + ".txt");
    vector<float> skaiciai;
    out_data << setw(20) << left << "Vardas"
        << setw(20) << left << "Pavarde"
        << setw(20) << left << "Galutinis(vid.)"
        << endl;
    for (int s = 1; s < studentuSkaicius; s++) {
        skaiciai = auto_marks(5);
        out_data << setw(20) << "Vardas" + to_string(s) <<
            setw(20) << "Pavarde" + to_string(s) <<
            setw(18) << count_gal(skaiciai, pagalMediana) << endl;;
        skaiciai.clear();
    }
    out_data.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failas su " << studentuSkaicius << " studentu kurimas uztruko: " << diff.count() << " s\n \n";

}