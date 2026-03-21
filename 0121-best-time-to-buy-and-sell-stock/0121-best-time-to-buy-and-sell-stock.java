class Solution {
    public int maxProfit(int[] prices) {
        int ans=0;
        int mini=prices[0];
        for(int i=1;i<prices.length;i++){
            mini=Math.min(mini,prices[i]);
            ans=Math.max(ans,prices[i]-mini);
        }
        return ans;
    }
}