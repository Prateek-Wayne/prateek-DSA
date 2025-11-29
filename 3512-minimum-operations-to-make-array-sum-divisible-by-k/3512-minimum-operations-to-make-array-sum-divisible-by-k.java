class Solution {
    public int minOperations(int[] nums, int k) {
        long sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=(long)nums[i];
        }
        return (int)sum%k;
    }
}