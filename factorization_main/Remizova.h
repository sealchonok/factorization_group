#pragma once
#include <vector>
template <typename T>
using Method = std::vector<T>(*)(T data);

std::vector<int> primeFactorization(int n);
