class Solution {
    public int maxSubArray(int[] nums) {
        int maxy=Integer.MIN_VALUE;
        int sum=0;
        for(int i:nums){
            sum+=i;
            maxy=Math.max(sum,maxy);
            if(sum<0)
                sum=0;
        }
        return maxy;
    }
}