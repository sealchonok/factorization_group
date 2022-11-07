/*
TODO: 
    Реализовать методы:
        Ленстры
        Перебора
        Полларда
        Ферма
        Диксона
        Лемана
*/

#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <regex>
#include <numeric>
#include <vector>
#include <locale>

using namespace std;

template <typename T>
using Method = std::vector<T>(*)(T data);

vector<int> primeFactorization(int n) {
    vector<int> ans;
    while (n % 2 == 0) {
        ans.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            ans.push_back(i);
        }
    }
    if (n > 2) { 
        ans.push_back(n);
    }
    return ans;
}

void print(std::vector<int> const& input)
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

static string dataset = "";
static vector<string> logs;


/*vector<int> data()
{
    return { 1775, 700, 12, 214, 2132, 24, 34, 412, 41, 47, 56, 59, 62, 62, 66, 69, 70,
        76, 84, 90, 103, 106, 107, 117, 124, 139, 149, 153, 162, 173, 180, 182,
        182, 201, 207, 224, 225, 226, 227, 238, 241, 243, 245, 254, 255, 257, 257,
        269, 278, 279, 280, 286, 288, 290, 292, 292, 296, 312, 317, 329, 330, 340,
        345, 348, 358, 364, 365, 367, 373, 375, 386, 387, 393, 394, 399, 403, 404,
        6, 90, 3, 56, 1, 100, 450, 34, 23, 98, 65, 54, 98, 12, 244, 345 };
}*/


template <typename T>
void Run(string method_name, Method<T> p, vector<int> data)
{
    for (int i = 0; i < data.size(); i++) {
        auto start = chrono::system_clock::now();
        vector<T> res = p(data[i]);
        auto stop = chrono::system_clock::now();
        auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();
        
        print(res);
        cout << endl << time <<endl;
    }

    
}

int main()
{

    setlocale(LC_ALL, "Ru"); // Устанавливаем Русскую локаль, поддерживающую вывод символов русского языка

    Run("primeFactorization", primeFactorization, { 1775, 700, 12, 214, 2132, 24, 34, 412, 41, 47, 56, 59, 62, 62, 66, 69, 70,
        76, 84, 90, 103, 106, 107, 117, 124, 139, 149, 153, 162, 173, 180, 182,
        182, 201, 207, 224, 225, 226, 227, 238, 241, 243, 245, 254, 255, 257, 257,
        269, 278, 279, 280, 286, 288, 290, 292, 292, 296, 312, 317, 329, 330, 340,
        345, 348, 358, 364, 365, 367, 373, 375, 386, 387, 393, 394, 399, 403, 404,
        6, 90, 3, 56, 1, 100, 450, 34, 23, 98, 65, 54, 98, 12, 244, 345 });
}

