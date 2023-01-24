class Solution {
public:
    int kadane(vector<int>& nums)
    {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
                sum=0;
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int x=kadane(nums);
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i]=nums[i]*-1;
        }
        int y=kadane(nums);
        if(sum+y==0)
            return x;
        int ans=max(x,sum+y);
        return ans;
    }
};