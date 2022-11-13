#include "Romanov.h"
//#include "Remizova.h"
#include <vector>
#include <set>
#include <numeric>

std::vector<int> DixonFactor(int N)
{
    std::vector<int> Bs = { 2, 3, 5, 7, 11 };    // B = 11
    
    std::vector< std::pair<int, int> > B_pairs;         // vector of pairs of B-smooth squares
    
    int sqrt_N = int(sqrt(N));      
    for (int i = sqrt_N; i < N; ++i)        // range from sqrt(N) to N
    {
        std::pair<int, int> v;
        for (int j : Bs)                    // Simplified algorithm to find related squares (leds to duplicates results)
        {
            int lhs = (i * i) % N;
            int rhs = (j * j) % N;

            if (lhs == rhs)
            {
                v = { i, j };
                B_pairs.push_back(v);
            }

        }
    }

    std::set<int> DivSet;                                 // use set to remove duplicates
    for (auto p : B_pairs) 
    {
        int div = std::gcd(p.first - p.second, N);        // GCD - greatest common divisor 

        if (div != 1)
            DivSet.emplace(div);
    }

    std::vector<int> result (DivSet.begin(), DivSet.end());
    return result;
}
