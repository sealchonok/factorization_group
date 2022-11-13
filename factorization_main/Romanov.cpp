#include "Romanov.h"
//#include "Remizova.h"
#include <vector>
#include <set>
#include <numeric>

std::vector<int> DixonFactor(int N)
{
    constexpr int Bs[] = { 2, 3, 5, 7, 11, 13 };    // B = 13
    
    std::vector< std::pair<int, int> > B_pairs;     // vector of pairs of B-smooth squares
    
    int sqrt_N = int(sqrt(N)) + 1;      
    for (int i = sqrt_N; i < N; ++i)        // range from sqrt(N) to N
    {
        for (int j : Bs)                    // Simplified algorithm to find related squares (leds to duplicated results)
        {
            int lhs = (i * i) % N;
            int rhs = (j * j) % N;

            if (lhs == rhs)
                B_pairs.emplace_back(i, j);
        }
    }

    std::set<int> DivSet;                               // use set to remove duplicates
    for (auto p : B_pairs) 
    {
        int div = std::gcd(p.first - p.second, N);      // GCD - greatest common divisor 

        if (div != 1 && div != N) {
            DivSet.emplace(div);
            DivSet.emplace(N / div);
        }
    }

    std::vector<int> result (DivSet.begin(), DivSet.end());
    return result;
}
