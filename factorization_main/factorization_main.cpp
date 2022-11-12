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

        print(res);
        cout << endl << time << endl;
    }


}


int main()
{
    vector<int> data = { 177408, 700, 12, 214, 2132, 24, 34, 412, 41, 47, 56, 59, 62, 62, 66, 69, 70,76, 84, 90, 103, 106, 107, 117, 124, 139, 149, 153, 162, 173, 180, 182,
        182, 201, 207, 224, 225, 226, 227, 238, 241, 243, 245, 254, 255, 257, 257,
        269, 278, 279, 280, 286, 288, 290, 292, 292, 296, 312, 317, 329, 330, 340,
        345, 348, 358, 364, 365, 367, 373, 375, 386, 387, 393, 394, 399, 403, 404,
        6, 90, 3, 56, 1, 100, 450, 34, 23, 98, 65, 54, 98, 12, 244, 345 };

    
    Run("Prime Factorization", primeFactorization, data);
    Run("Dixon Factorization", DixonFactor, data);
    Run("Pollard Po", PollardPo, data);
}


