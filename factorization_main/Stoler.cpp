
#include<vector>
#include "Remizova.h"
#include <numeric>
using namespace std;

int singlePollard(int n) {
	vector<int> val;
	int temp;
	val.push_back(1);

	for (int i = 1; i <= n; i++) {

		temp = val.back();
		val.push_back((val.back() * val.back() + 1) % n);
		int d = gcd(n, abs(val[i] - val[i / 2]));
		if (d > 1)
			return d;
	}
}

vector<int> PollardPo(int n) {
	vector<int> ans;

	while (n != 1)
	{
		ans.push_back(singlePollard(n));
		n /= ans.back();
	}

	return ans;
}