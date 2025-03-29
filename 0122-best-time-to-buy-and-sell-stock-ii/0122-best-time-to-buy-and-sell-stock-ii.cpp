class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> nextLargest(n, -1);
        for (int i = n - 2; i >= 0; i--) {
            if (prices[i] < prices[i + 1])
                nextLargest[i] = prices[i + 1];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (nextLargest[i] != -1)
                ans += (nextLargest[i] - prices[i]);
        }
        return ans;
    }
};