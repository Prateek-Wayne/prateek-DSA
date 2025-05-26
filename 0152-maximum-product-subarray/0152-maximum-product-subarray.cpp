class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxy=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ans=nums[i];
            for(int j=i+1;j<n;j++)
            {
                ans=ans*nums[j];
                maxy=max(ans,maxy);
            }
        }
        for(int i=0;i<n;i++){
            maxy=max(maxy,nums[i]);
        }
        return maxy;
    }
};