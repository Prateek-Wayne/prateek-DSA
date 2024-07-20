class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit=arr[0];
        int diff=0;
        for(int i=0;i<arr.size();i++)
        {
            profit=min(profit,arr[i]);
            diff=max(diff,arr[i]-profit);
        }
        return diff;
    }
};