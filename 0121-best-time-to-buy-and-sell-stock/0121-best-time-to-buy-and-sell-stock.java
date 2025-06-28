class Solution {
    public int maxProfit(int[] prices) {
        int maxy=Integer.MIN_VALUE;
        int mini=Integer.MAX_VALUE;
        for(int i=0;i<prices.length;i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            maxy=Math.max(maxy, prices[i]-mini);
        }
        return maxy;
    }
}