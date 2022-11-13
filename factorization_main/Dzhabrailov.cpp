#include <iostream>
#include <vector>

using namespace std;

vector<int> Ferma(int n)
{
    vector<int> data;
    int s;
    float y;
    while (n % 2 == 0)
    {
        data.push_back(2);
        n /= 2;
    }

    if (n <= 2)
    {
        return data;
    }
    s = sqrt(n);
    int k = 0;
    do
    {
        k++;
        y = (s + float(k)) * (s + float(k)) - float(n);

    } while ((int)sqrt(y) != sqrt(y));
    int x = k + s;
    y = sqrt(y);
    int a1 = x - y;
    int a2 = x + y;

    while (a1 % 2 == 0)
    {
        data.push_back(2);
        a1 /= 2;
    }

    while (a2 % 2 == 0)
    {
        data.push_back(2);
        a2 /= 2;
    }

    for (int i = 3; i * i <= a1; i += 2)
    {
        while (a1 % i == 0)
        {
            a1 /= i;
            data.push_back(i);
        }
    }

    for (int i = 3; i * i <= a2; i += 2)
    {
        while (a2 % i == 0)
        {
            a2 /= i;
            data.push_back(i);
        }
    }

    if (a1 >= 2)
    {
        data.push_back(a1);
    }
    if (a2 >= 2)
    {
        data.push_back(a2);
    }

    return data;
}