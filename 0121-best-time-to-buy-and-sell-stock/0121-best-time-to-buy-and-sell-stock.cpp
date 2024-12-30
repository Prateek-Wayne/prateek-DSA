class Solution {
public:
  int maxProfit(vector<int> &prices)
{
    int ans = 0;
    int minElement = prices[0];
    for (int i = 0; i < prices.size(); i++)
    {
         minElement = min(prices[i], minElement);
        ans = max(ans, prices[i] - minElement);
    }
    return ans;
}
};