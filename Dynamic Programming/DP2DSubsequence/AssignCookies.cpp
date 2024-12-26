#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> &g, vector<int> &s)
{
    int m = s.size();
    int n = g.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        if (g[j] <= s[i])
            j++;
        i++;
    }
    return j;
}
int main()
{
    return 0;
}