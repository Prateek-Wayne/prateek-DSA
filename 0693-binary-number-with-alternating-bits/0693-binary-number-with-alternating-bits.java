class Solution {
    public boolean hasAlternatingBits(int n) {
        int prev=n&1;
        n=n>>1;
        while(n!=0){
            if(((n&1) == 0) && (prev!=1))
            {
                return false;
            }
            else if(((n&1) == 1) && (prev!=0)){
                return false;
            }
            prev=n&1;
            n=n>>1;
        }
        return true;
    }
}