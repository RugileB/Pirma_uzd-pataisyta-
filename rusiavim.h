#pragma once
#include "strukt.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;
using std::remove;




bool smart(studentas studentas) {
    return studentas.gal >= 5;
}


void rusiavimasIGtrupes(vector<studentas> studentai) {
    vector<studentas> protingi;
    vector<studentas> vargsiukai;

    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& stu : studentai) {
        if (smart(stu))
            protingi.push_back(stu);
        else
            vargsiukai.push_back(stu);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo rusiavimas 1 strategija su " + to_string(studentai.size()) + " studentais uztruko naudojant vector: "
        << diff.count()
        << " s\n";

}

void rusiavimasIGtrupes(list<studentas> studentai) {
    int kiek = studentai.size();
    list<studentas> vargsiukai;
    list<studentas> protingi;

    auto start = std::chrono::high_resolution_clock::now();
    for (const auto& stu : studentai) {
        if (smart(stu))
            protingi.push_back(stu);
        else
            vargsiukai.push_back(stu);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo rusiavimas 1 strategija su " + to_string(kiek) + " studentais uztruko naudojant list: "
        << diff.count()
        << " s\n";

}

bool varg(studentas studentas) {
    return studentas.gal < 5;
}

void rusiavimas2(vector<studentas> studentai) {
    int kiek = studentai.size();
    vector<studentas> vargsiukai;

    std::copy(
        std::begin(studentai),
        std::end(studentai),
        std::back_inserter(vargsiukai));

    auto start = std::chrono::high_resolution_clock::now();
    std::remove_if(studentai.begin(), studentai.end(), varg);
    std::remove_if(vargsiukai.begin(), vargsiukai.end(), smart);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo rusiavimas 2 strategija su " + to_string(kiek) + " studentais uztruko naudojant vector: " << diff.count()
        << " s\n \n";

}

void rusiavimas2(list<studentas> studentai) {
    int kiek = studentai.size();
    list<studentas> vargsiukai;

    std::copy(
        std::begin(studentai),
        std::end(studentai),
        std::back_inserter(vargsiukai));

    auto start = std::chrono::high_resolution_clock::now();
    std::remove_if(studentai.begin(), studentai.end(), varg);
    std::remove_if(vargsiukai.begin(), vargsiukai.end(), smart);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo rusiavimas 2 strategija su " + to_string(kiek) + " studentais uztruko naudojant list: " << diff.count()
        << " s\n \n";

}