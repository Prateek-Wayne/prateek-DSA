#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices)
{
    int ans = 0;
    int minElement = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
        int minElement = min(prices[i], minElement);
        ans = max(ans, prices[0] - minElement);
    }
    return ans;
}

int main()
{
    return 0;
}