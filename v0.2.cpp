// v0.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <fstream>
#include <time.h>
#include <sstream>

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

struct studentas {
    string vard, pavard;
    vector<float> nd;
    float egzam{};
    float gal{};
    float med{};
};

void pazymiuAutomatisPildymas();
void rankinisPildymas();
void printas(studentas);
double mediana(vector<float>& vec);
int random_sk();
unsigned int countWordsInString(string const& str);
void read_from_file(vector<studentas>& grupe);
void spausdinti(vector<studentas> grupe);

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


double mediana(vector<float>& vec) {
    typedef vector<float>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("Negalima skaiciuoti medianos tusciam vektoriui");
    sort(vec.begin(), vec.end());  //surusiuojame vektoriu i variacine eilute
    vecSize vid = size / 2;  //vidurinis vektoriaus elementas
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid];
}

int random_sk() //sugeneruoja bet koki skaiciu nuo 1 iki 10
{
    return rand() % 10 + 1;
}

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

void read_from_file(vector<studentas>& grupe) {
    int iteracija = 0;
    int temp;
    int pazymiuSkaicius;
    ifstream fileRead("C:\\Users\\Envy\\Desktop\\Objektinio uzduotys\\studentai10000.txt.txt");
    string buffer;
    if (fileRead.is_open()) {
        getline(fileRead >> std::ws, buffer);
        pazymiuSkaicius = countWordsInString(buffer) - 3;
        while (true) {
            grupe.resize(grupe.size() + 1);
            fileRead >> grupe.at(iteracija).vard;
            if (fileRead.eof()) {
                grupe.pop_back();
                break;
            }
            fileRead >> grupe.at(iteracija).pavard;
            for (int i = 0; i < pazymiuSkaicius; i++) {
                fileRead >> temp;
                grupe.at(iteracija).nd.push_back(temp);
            }
            fileRead >> grupe.at(iteracija).egzam;
            grupe.at(iteracija).gal = grupe.at(iteracija).gal / pazymiuSkaicius;
            grupe.at(iteracija).gal = grupe.at(iteracija).gal * 0.4 + 0.6 * grupe.at(iteracija).egzam;
            grupe.at(iteracija).med = mediana(grupe.at(iteracija).nd);
            iteracija++;
        }
    }
    else { cout << "-\n"; }
}

unsigned int countWordsInString(string const& str) {
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<string>(stream), std::istream_iterator<string>());
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
