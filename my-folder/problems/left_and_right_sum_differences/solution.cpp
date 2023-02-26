class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n=nums.size();
        int left[n];
        int right[n];
        left[0]=0;
        for(int i=1;i<n;i++)
        {
            left[i]=left[i-1]+nums[i-1];
        }
        right[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            right[i]=right[i+1]+nums[i+1];
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(abs(left[i]-right[i]));
        }
        return ans;
        
    }
};