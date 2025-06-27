class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxy=0;
        int ones=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1){
                ones++;
                maxy=Math.max(maxy,ones);
            }
            else
            {
                maxy=Math.max(maxy,ones);
                ones=0;
            }
        }
        return maxy;
    }
}