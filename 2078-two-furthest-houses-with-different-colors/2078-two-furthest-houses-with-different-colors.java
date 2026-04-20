class Solution {
    public int maxDistance(int[] colors) {
        int ans=0;
        int n=colors.length;
        for(int i=0;i<n;i++){
            if(colors[i]!=colors[0]){
                ans=Math.max(ans,Math.abs(i-0));
            }
        }
        for(int i=n-1;i>=0;i--){
            if(colors[i]!=colors[n-1]){
                ans=Math.max(ans,Math.abs(n-1-i));
            }
        }
        return ans;
    }
}