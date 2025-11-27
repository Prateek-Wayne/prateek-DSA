class Solution {
    public int getSecondLargest(int[] arr) {
        // code here
        int firstMax=Integer.MIN_VALUE;
        int secondMax=-1;
        for(int i:arr){
            firstMax=Math.max(firstMax,i);
        }
        for(int i:arr){
            if(i!=firstMax)
                secondMax=Math.max(secondMax,i);
        }
        return secondMax;
    }
    }
