#include "vector.h"
#include <iostream>
#include <chrono>
#include <cstddef>
#include <cassert>
#include <stdexcept>
#include <vector>
#include <chrono>
#include <iomanip>
int main(){


 

unsigned int sz = 100000000; // 100000, 1000000, 10000000, 100000000

 
auto start = std::chrono::high_resolution_clock::now();
std::vector<int> v1;

 

for (int i = 1; i <= sz; ++i) v1.push_back(i);

 auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed = end - start;
std::cout << std::fixed << std::setprecision(6) << "std::vector fill time: " << elapsed.count() << " seconds\n";

// Baigti v1 užpildymo laiko matavimą

 

// Pradėti v2 užpildymo laiko matavimą

 auto start2 = std::chrono::high_resolution_clock::now();


Vector<int> v2;

 

for (int i = 1; i <= sz; ++i) v2.push_back(i);

 auto end2 = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> elapsed2 = end2 - start2;
std::cout << std::fixed << std::setprecision(6) << "Custom Vector fill time: " << elapsed2.count() << " seconds\n";

// Baigti v2 užpildymo laiko matavimą
}