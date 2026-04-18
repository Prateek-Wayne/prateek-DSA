class Solution {
    public int mirrorDistance(int n) {
        int originalNumber=n;
        int reverse=0;
        while(n!=0){
            int lastNumber=n%10;
            reverse=reverse*10+lastNumber;
            n=n/10;
        }
        return Math.abs(originalNumber-reverse);
    }
}