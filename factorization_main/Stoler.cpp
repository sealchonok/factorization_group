#include "Stoler.h"
#include<vector>
#include <numeric>
using namespace std;

vector<int> PollardPo(int n) {
    vector<int> ans;
    for (int x = 1; x < n - 2; ++x) {
        int y = 1; int i = 0; int stage = 2;
        while (gcd(abs(x - y), n) == 1) {
            if (i == stage) {
                y = x;
                stage = stage * 2;
            }
            x = (x * x + 1);
            i += 1;
        }
        ans.push_back(gcd(abs(x - y), n));
    }
    return ans;
}