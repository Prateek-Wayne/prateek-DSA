class Solution {
public:
    int kadane(vector<int> num)
    {
        int maxSum=INT_MIN;
        int sum=0;
        for(int i=0;i<num.size();i++)
        {
            sum+=num[i];
            maxSum=max(maxSum,sum);
            if(sum<0)
                sum=0;
        }
        return maxSum;    
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        
        // applyin kadane...
        int onlyKadane=kadane(nums);
        
        // modifyinh array ...
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            nums[i]*=-1;
        }
        // applying kadane here
        int modified=kadane(nums);
        int ans=modified+sum;
        if(ans==0)
            return onlyKadane;
        
        return max(ans,onlyKadane);
        
        
    }
};