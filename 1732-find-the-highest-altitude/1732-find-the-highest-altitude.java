class Solution {
    public int largestAltitude(int[] gain) {
        int ans=0;
        int maxy=0;
        for(int i:gain){
            ans+=i;
            maxy=Math.max(maxy,ans);
        }
        return maxy;
    }
}