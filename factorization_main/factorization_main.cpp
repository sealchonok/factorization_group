#include <chrono>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <numeric>
#include <vector>
#include <iostream>
#include <fstream>
#include <locale>

#include "Remizova.h"
#include "Romanov.h"
#include "Stoler.h"
#include "Pakhomov.h"

using namespace std;

void print(std::vector<int> const& input)
{
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ' ';
    }
}

template <typename T>
void Run(string method_name, Method<T> p, vector<int> data)
{
    cout << endl << method_name << endl;
    for (int i = 0; i < data.size(); i++) {
        cout << "Число: " << data[i] << endl;

        auto start = chrono::system_clock::now();
        vector<T> res = p(data[i]);
        auto stop = chrono::system_clock::now();
        auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

        cout << "\tРазложение: ";
        print(res);
        cout << endl << "\tВремя (мкс): " << time << endl;
    }


}


int main()
{
    setlocale(LC_ALL, "Ru");

    vector<int> data = { 13029, 202429, 591157, 891265, 1113121, 25060027, 33550369, 59549297, 102941291, 396501869, 1244502576, 1403943942 };
   
    
    // Run("Pollard Po", PollardPo, data);
    Run("Pollard_P1", Pollard_P1, data);
    Run("Prime Factorization", primeFactorization, data);
    // Run("Dixon Factorization", DixonFactor, data);
    Run("Lenstra’s Elliptic Curve Factorization", EllipticCurveFactorisation, data);
  
}


