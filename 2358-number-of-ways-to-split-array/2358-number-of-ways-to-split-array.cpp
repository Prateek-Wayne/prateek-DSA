class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long> arr(n,0);
        arr[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            arr[i]=nums[i]+arr[i-1];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]>=arr[n-1]-arr[i])
                count++;
        }
        return count;
    }
};