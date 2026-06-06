class Solution {
    public int[] leftRightDifference(int[] nums) {
        int n=nums.length;
        int[]left=new int[n];
        int[] right=new int[n];
        int sum=0;
        left[0]=sum;
        for(int i=1;i<n;i++){
            sum+=nums[i-1];
            left[i]=sum;
        }
        sum=0;
        right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            sum+=nums[i+1];
            right[i]=sum;
        }
        int[] solve=new int[n];
        for(int i=0;i<n;i++){
            int diff=Math.abs(left[i]-right[i]);
            solve[i]=diff;
        }
        return solve;
    }
}