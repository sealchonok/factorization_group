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
    auto av_time = 0;
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
        av_time = av_time + time;
    }
    cout << endl << "\tСреднее для тестов (мкс): " << (av_time/data.size()) << endl;


}


int main()
{
    setlocale(LC_ALL, "Ru");

    vector<int> data = { 12, 225, 113, 2056, 34560, 7884392};
   
    
    Run("Pollard Po", PollardPo, data);
    Run("Prime Factorization", primeFactorization, data);
    Run("Dixon Factorization", DixonFactor, data);
    Run("Lenstra’s Elliptic Curve Factorization", EllipticCurveFactorisation, data);
    Run("Ferma", Ferma, data);
    Run("Pollard_P1", Pollard_P1, data);
  
}


