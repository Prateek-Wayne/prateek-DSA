class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int miny=arr[0];
        int max_profit=0;
        for(int i=1;i<arr.size();i++)
        {
            miny=min(miny,arr[i]);
            int profit=arr[i]-miny;
            max_profit=max(max_profit,profit);
        }
        return max_profit;
    }
};