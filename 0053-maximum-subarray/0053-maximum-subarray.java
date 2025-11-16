class Solution {
    public int maxSubArray(int[] nums) {
        int sum=0;
        int maxy=Integer.MIN_VALUE;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            maxy=Math.max(sum,maxy);
            if(sum<0){
                sum=0;
            }
        }
        return maxy;
    }
}