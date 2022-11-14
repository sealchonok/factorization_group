#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

int gcd(int a, int b) // Âû÷èñëåíèå ÍÎÄ
{
	if (a < 0)
		return 2;
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

bool isPrime(int n) // Ïðîâåðêà, ÿâëÿåòñÿ ëè ÷èñëî ïðîñòûì
{
	if (n <= 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
			return false;
	return true;
}

int pollard(int n) 
{
	long long a = 2;
	int i = 2;
	while (true)
	{
		a = ((long long)pow(a, i)) % n;
		int d = gcd(a - 1, n); 
		if (d > 1)
		{
			return d;
			break;
		}
		i += 1;
	}
}



vector<int> Pollard_P1(int n)
{
	int num = n;
	if (isPrime(num)) {
		cout << "Your number is prime" << endl;

	}
	else {
		vector<int> ans;
		while (true)
		{
			int d = pollard(num);
			ans.push_back(d);
			int r = (num / d);
			if (isPrime(r))
			{
				ans.push_back(r);
				break;
			}
			else
				num = r;
		}
		return ans;
	}
}

