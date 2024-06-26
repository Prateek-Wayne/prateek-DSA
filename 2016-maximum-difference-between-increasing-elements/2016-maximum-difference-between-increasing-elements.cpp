class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int miny=nums[0];
        int diff=-1;
        for(int i=1;i<nums.size();i++)
        {   
            if(nums[i]==miny)
                continue;
            diff=max(diff,nums[i]-miny);
            
            miny=min(miny,nums[i]);
            
        }
        return diff;
        
    }
};