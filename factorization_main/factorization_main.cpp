﻿#include <chrono>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <numeric>
#include <vector>
#include <iostream>
#include <fstream>
#include "Remizova.h"
#include "Romanov.h"
#include "Stoler.h"
using namespace std;
void print(std::vector<int> const& input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

template <typename T>
void Run(string method_name, Method<T> p, vector<int> data)
{
    cout << method_name << endl;
    for (int i = 0; i < data.size(); i++) {
        auto start = chrono::system_clock::now();
        vector<T> res = p(data[i]);
        auto stop = chrono::system_clock::now();
        auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();

        cout << data[i] << ":\n";
        print(res);
        cout << "\n" << time << " ms.\n\n";
    }


}


int main()
{
    vector<int> data = { 300564, 319, 18419, 123455, 23449, 84923, 2225, 300, 35, 150, 12, 30, 444, 22, 660, };
   
    
   //Run("Pollard Po", PollardPo, data);
   //Run("Pollard_P1", Pollard_P1, data);
   Run("Prime Factorization", primeFactorization, data);
   Run("Dixon Factorization", DixonFactor, data);
  
}


