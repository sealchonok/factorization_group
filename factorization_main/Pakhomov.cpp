#include <tuple>
#include <vector>
#include <random>
#include <cmath>
#include "Remizova.h"

#define INF numeric_limits<int>::max()

using namespace std;

long long __fact(long long a)
{
    return (a) ? __fact(a - 1) * a : 1;
}

tuple<int, int, int> __xgcd(int a, int b)                               // ax + by = gcd(a, b). This function returns [gcd(a, b), x, y]. Source Wikipedia.
{
    int keep, x = 0, y = 1, lastx = 1, lasty = 0;
    int q;

    while (b != 0)
    {
        q = a / b;                              // Regular gcd(a, b) calculation
        keep = a;
        a = b;
        b = keep % a;

        keep = x;                               // X shift keeping previous x
        x = lastx - q * x;
        lastx = keep;

        keep = y;                               // Y shift keeping previous y
        y = lasty - q * y;
        lasty = keep;
    }

    if (a < 0)                                  // Value reverse if gcd(a, b) < 0
    {
        a = -a;
        lastx = -lastx;
        lasty = -lasty;
    }

    return { (int)a, lastx, lasty };
}

int __randnum(int max)
{
    random_device rd;                                   // Only used once to initialise (seed) engine
    mt19937 rng(rd());                                  // Random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<int> uni(1, max);          // Guaranteed unbiased

    auto random_integer = uni(rng);
    return random_integer;
}

tuple<int, int, pair<int, int>> __randcurve(int n)                         // y^2 = x^3 + Ax + B (mod n). This function returns [A, B, n, x, y], where
{
    pair<int, int> P = { __randnum(n), __randnum(n) };                          // P = (x, y) is a point with random non-zero coordinates x, y (mod n)
    int A = __randnum(n);                                                       // A is a random non-zero integer A (mod n). Source Wikipedia.

    int B = (P.first * P.first - P.second * P.second * P.second - A * P.second) % n;

    return { A, B, P };
}

tuple<pair<int, int>, int> __sumpoint(int A, int B, int n, pair<int, int> P, pair<int, int> Q)
{
    if (P == make_pair(INF, INF))
        return { Q, 1 };
    if (Q == make_pair(INF, INF))
        return { P, 1 };

    int xP, yP, xQ, yQ, xR, yR;
    int u, v, slope;
    int div;
    tie(xP, yP) = P;
    tie(xQ, yQ) = Q;

    xP %= n;
    yP %= n;
    xQ %= n;
    yQ %= n;

    if (xP != xQ)
    {
        tie(div, u, v) = __xgcd(xP - xQ, n);
        slope = ((yP - yQ) * u) % n;
        xR = (slope * slope - xP - xQ) % n;
        yR = (slope * (xP - xR) - yP) % n;
    }
    else
    {
        if ((yP + yQ) % n == 0)
        {
            xR = INF;
            yR = INF;
            div = 1;
        }
        else
        {
            tie(div, u, v) = __xgcd(2 * yP, n);
            slope = (3 * xP * xP + A) % n;
            xR = (slope * slope - 2 * xP) % n;
            yR = (slope * (xP - xR) - yP) % n;
        }
    }

    return { {xR, yR}, div };
}

tuple<pair<int, int>, int> __mulpoint(int A, int B, int n, pair<int, int>& P)
{
    pair<int, int> R = { INF, INF };
    int div = 1;

    for (long long e = __fact(18); e > 0; e = e >> 1)
    {
        if (e % 2)
            tie(R, div) = __sumpoint(A, B, n, R, P);
        if (div != 1)
            return { R, div };
        tie(P, div) = __sumpoint(A, B, n, P, P);
        if (div != 1)
            return { R, div };
    }
    return { R, div };
}

long long __mindiv(int n, int times = 50)
{
    int A, B;
    int div;
    pair<int, int> P, R;

    for (int i = 0; i < times; i++)
    {
        tie(A, B, P) = __randcurve(n);
        tie(R, div) = __mulpoint(A, B, n, P);
        if (div != 1 && div != n)
            return div;
    }
    return n;
}

vector<int> EllipticCurveFactorisation(int n)
{
    vector<int> results;
    int number = n, divisor;

    while (number != 1)
    {
        divisor = __mindiv(number);
        results.push_back(divisor);
        number /= divisor;
    }

    sort(results.begin(), results.end());

    return results;
}
