#include <bits/stdc++.h>
using namespace std;

int helper(string &s, string &t, int ind1, int ind2)
{
    if (ind2 < 0)
        return 1;
    if (ind1 < 0)
        return 0;

    if (s[ind1] == t[ind2])
    {
        return helper(s, t, ind1 - 1, ind2 - 1) + helper(s, t, ind1 - 1, ind2);
    }
    return helper(s, t, ind1 - 1, ind2);
}

int numDistinct(string s, string t)
{
    int ind1 = s.length() - 1;
    int ind2 = t.length() - 1;
    
    return helper(s, t, ind1, ind2);
}
int main()
{
    string s = "rabbbit";
    string t = "rabbit";
    cout << numDistinct(s, t);
    return 0;
}