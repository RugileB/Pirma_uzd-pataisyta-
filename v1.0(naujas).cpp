// v1.0(naujas).cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "strukt.h"
#include "mediana.h"
#include "failo_skait.h"
#include "spausdinimas.h"
#include "failo_generavimas.h"
#include "rusiavim.h"
#include <vector>
#include <list>

using namespace std;
using std::list;

int main() {
    
    for (int i = 1000; i < 10000001; i *= 10) {
        generavimas(i, false);
        vector<studentas> grupeStudentuVector;
        list<studentas> grupeStudentuList;
        readFromFile2(grupeStudentuVector, i);
        rusiavimasIGtrupes(grupeStudentuVector);
        rusiavimas2(grupeStudentuVector);
        readFromFile2(grupeStudentuList, i);
        rusiavimasIGtrupes(grupeStudentuList);
        rusiavimas2(grupeStudentuList);
    }
    return -1;
    
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
