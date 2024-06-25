class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
    int breakPoint = -1;
    // findiing breakPoint....
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            breakPoint = i;
            break;
        }
    }
    if(breakPoint==-1)
    {
        reverse(nums.begin(),nums.end());
        return ;
    }
    // findinf next greatest number.(we know after breakpoint array will be sorted already...)
    for(int i=n-1;i>breakPoint;i--)
    {
           if (nums[i] > nums[breakPoint])
        {
            swap(nums[i], nums[breakPoint]);
            break;
        }
        
    }
    // now reverse array from breakpoint to end...
    reverse(nums.begin()+breakPoint+1,nums.end());
    return;
    }
};