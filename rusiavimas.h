#pragma once
#include "struktura.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std;


void rusiavimas(vector<studentas> studentai) {
	vector<studentas> protingi;
	vector<studentas> vargsiukai;

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < studentai.size(); i++) {
		float paz = 5.00;
		if (studentai.at(i).gal < paz) {
			vargsiukai.push_back(studentai.at(i));
		}
	}
	for (int j = 0; j < studentai.size(); j++) {
		float paz = 5.00;
		if (studentai.at(j).gal >= paz) {
			protingi.push_back(studentai.at(j));
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	cout << "Failo rusiavimas su " + to_string(studentai.size()) + " studentais i dvi grupes uztruko : " << diff.count()
		<< " s\n";

	// Vargsiukai
	std::ofstream vargs_failas("vargsiukai_" + to_string(studentai.size()) + ".txt");
	auto start1 = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < vargsiukai.size(); i++) {
		vargs_failas << vargsiukai.at(i).vard << setw(20) << vargsiukai.at(i).pavard << setw(18)
			<< vargsiukai.at(i).gal << endl;
	}
	vargs_failas.close();
	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	cout << "Failo isvedimas su " + to_string(studentai.size()) + " studentais  i vargsiukus uztruko : " << diff1.count()
		<< " s\n";

	// Protingieji
	std::ofstream prot_failas("protingi_" + to_string(studentai.size()) + ".txt");
	auto start2 = std::chrono::high_resolution_clock::now();
	for (int j = 0; j < protingi.size(); j++) {
		prot_failas << protingi.at(j).vard << setw(20) << protingi.at(j).pavard << setw(18)
			<< protingi.at(j).gal << endl;
	}
	prot_failas.close();
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2;
	cout << "Failo isvedimas su " + to_string(studentai.size()) + " studentais  i protingus uztruko : " << diff2.count()
		<< " s\n";
	system("pause");
}