#include "mediana.h"
#include <stdexcept>
#include <algorithm>
#include <vector>

double mediana(vector<float>& vec) {
    typedef vector<float>::size_type vecSize;
    vecSize size = vec.size();
    if (size == 0)
        throw std::domain_error("Negalima skaiciuoti medianos tusciam vektoriui");
    try {
        sort(vec.begin(), vec.end());  //surusiuojame vektoriu i variacine eilute
    }
    catch (int e) { 
    }
    vecSize vid = size / 2;  //vidurinis vektoriaus elementas
    return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2 : vec[vid];
}