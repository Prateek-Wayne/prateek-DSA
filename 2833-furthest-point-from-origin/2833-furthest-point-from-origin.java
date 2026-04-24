class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int count=0;
        int extras=0;
        for(int i=0;i<moves.length();i++){
            char c=moves.charAt(i);
            if(c=='L')
                count--;
            else if(c=='R')
                count++;
            else if(c=='_')
                extras++;
        }
        count=Math.abs(count);
        count+=extras;
        return count;
        
    }
}