class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(start-i>=0 && nums[start-i]==target)
                return i;
            if(start+i<n && nums[start+i]==target)
                return i;
        }
        return -1;
    }
}