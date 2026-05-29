class Solution {
    int findSumOfAllDigits(int n){
        int sum=0;
        while(n!=0){
            int firstDigit=n%10;
            sum+=firstDigit;
            n=n/10;
        }
        return sum;
    }
    public int minElement(int[] nums) {
        int mini=Integer.MAX_VALUE;
        for(int i:nums){
            mini=Math.min(mini,findSumOfAllDigits(i));
        }
        return mini;
    }
}