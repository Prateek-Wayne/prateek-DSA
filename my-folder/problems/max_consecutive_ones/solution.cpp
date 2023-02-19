class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int maxy=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
            else
            {
                maxy=max(count,maxy);
                count=0;
            }
            
        }
        maxy=max(count,maxy);
        return maxy;
    }
};