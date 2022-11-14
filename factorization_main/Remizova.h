#pragma once
#include <vector>
template <typename T>
using Method = std::vector<T>(*)(T data);

std::vector<int> primeFactorization(int n);
std::vector<int> DixonFactor(int N);
std::vector<int> Pollard_P1(int N);
std::vector<int> Ferma(int N);
std::vector<int> PollardPo(int n);
std::vector<int> EllipticCurveFactorisation(int n);