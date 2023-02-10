class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit=0;
        int n=arr.size();
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]<arr[i+1])
            {
                profit+=(arr[i+1]-arr[i]);
            }
        }
        return profit;
    }
};