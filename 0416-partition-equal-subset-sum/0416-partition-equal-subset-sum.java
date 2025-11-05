class Solution {
 static Boolean helper(int arr[], int sum, int index, Boolean[][] dp) {
        if (sum == 0)
            return true;
        if (index >= arr.length || sum <= 0)
            return false;
        if (dp[index][sum] != null)
            return dp[index][sum];
        boolean left = helper(arr, sum - arr[index], index + 1, dp);
        boolean right = helper(arr, sum, index + 1, dp);
        return dp[index][sum] = left || right;
    }

    public boolean canPartition(int[] nums) {
        int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum%2!=0)
            return false;
        sum=sum/2;
        Boolean[][] dp=new Boolean[nums.length][sum+1];
        return helper(nums, sum, 0, dp);
    }

}