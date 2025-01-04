#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int helper(int n, vector<int> &dp)
{

    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    long long first = 1 + ((n * (n - 1)) / 2);
    long long temp = 1;
    for (long long i = 0; i < n; i++)
        temp = (temp * (first + i)) % MOD;
    return dp[n] = (temp + helper(n - 1, dp)) % MOD;
}

long long sequence(int n)
{
    vector<int> dp(n + 1, -1);
    long long ans = helper(n, dp);
    return ans % MOD;
}
int main()
{
    cout << sequence(11);
    return 0;
}