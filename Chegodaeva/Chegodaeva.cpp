#include <iostream> 
#include <vector> 
#include <string> 
using namespace std;

int gcd(int a, int b) // Вычисление НОД
{
	if (a < 0)
		return 2;
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

bool isPrime(int n) // Проверка, является ли число простым
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

int pollard(int n) //Генерация простых множителей
{
	long long a = 2;
	int i = 2;
	while (true)
	{
		a = ((long long)pow(a, i)) % n;
		int d = gcd(a - 1, n); //Среднее арифметическое
		if (d > 1)
		{
			return d;
			break;
		}
		i += 1;
	}
}

int check() 
{
	string s;
	bool check_point = true;
	cout << "Enter the number:" << endl;
	while (check_point) 
	{
		check_point = false;
		getline(cin, s); //Считывание числа как строки
		for (int i = 0; i < s.length(); i++)
		{
			if (!isdigit(s[i]))
			{
				cout << "You entered the characters or your number is not integer!" << endl;
				cout << "Please, enter new number:" << endl;
				check_point = true;
				break;
			}
		}
	}
	int num = stoi(s); //Приведение строки к типу int
	if (isPrime(num)) { //Проверка на простоту
		cout << "Your number is prime" << endl;
		return 0;
	}
	return num;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = check();
	if (!n) {
		return 0;
	}
	int num = n;
	vector<int> ans; //Список для хранения простых множителей
	while (true)
	{
		int d = pollard(num);
		ans.push_back(d); //Добавление полученного в список
		int r = (num / d);
		if (isPrime(r))
		{
			ans.push_back(r);
			break;
		}
		else 
			num = r;
	}
	cout << "Prime factors of " << n << " are ";
	for (int elem : ans)
		cout << elem << " ";
}