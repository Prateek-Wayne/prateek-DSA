#include <bits/stdc++.h>
using namespace std;

int func(int x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }
    if (n % 2 == 0)
        return func(x * x, n / 2);
    else
    {
        return x * func(x, n - 1);
    }
}

int myPow(int x, int n)
{
    int num = n;
    return func(x, num);
}

int countGoodNumbers(long long n)
{
    int mod = 1e9 + 7;
    int even = n / 2 + n % 2;
    int odd = n / 2;
    int result = (myPow(5, even) % mod) * (myPow(4, odd) % mod) % mod;
    return result;
}

int main()
{
    return 0;
}