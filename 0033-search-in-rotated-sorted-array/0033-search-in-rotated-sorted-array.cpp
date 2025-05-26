class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return mid;
            // search only in sorted part...
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && nums[mid]>=target)
                {
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            else
            {
                // right is sorted...
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                }
                else
                    high=mid-1;
            }
        }
        return -1;
    }
};