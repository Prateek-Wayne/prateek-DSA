class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int miny=arr[0];
        int diff=0;
        for(int i=1;i<arr.size();i++)
        {
            miny=min(miny,arr[i]);
            diff=max(diff,arr[i]-miny);
        }
        return diff;
        
    }
};