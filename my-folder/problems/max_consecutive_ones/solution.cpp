class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int count=0;
        for(auto i:nums)
        {
            if(i==1)
            {
                count++;
            }
            else{
                maxi=max(maxi,count);
                count=0;
            }
          
        }
        maxi=max(count,maxi);
        return maxi;
    }
};