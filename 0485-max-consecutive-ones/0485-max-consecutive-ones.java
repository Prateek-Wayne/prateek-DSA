class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxy=0;
        int count=0;
        for(int i:nums){
            if(i==1){
                count++;
                maxy=Math.max(count,maxy);
            }
            else{
                count=0;
            }
        }
        return maxy;
    }
}