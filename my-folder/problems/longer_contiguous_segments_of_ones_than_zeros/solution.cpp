class Solution {
public:
     int find_length(string nums,char x) {
        int count=0;
        int maxy=0;
        for(int i=0;i<nums.length();i++)
        {
            if(nums[i]==x)
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
    bool checkZeroOnes(string s) {
        if(find_length(s,'1')>find_length(s,'0'))
            return true;
        else
            return false;
    }
};