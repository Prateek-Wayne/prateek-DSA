class Solution {
    public int countGoodSubstrings(String s) {
        int n=s.length();
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            if(j-i+1==3){
                if(s.charAt(i)!=s.charAt(i+1) && s.charAt(i+1)!=s.charAt(i+2) 
                && s.charAt(i+2)!=s.charAt(i))
                    count++;
                i++;
            }
            j++;
        }
        return count;
    }
}