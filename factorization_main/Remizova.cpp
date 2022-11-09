#include "Remizova.h"
#include<vector>
using namespace std;

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
