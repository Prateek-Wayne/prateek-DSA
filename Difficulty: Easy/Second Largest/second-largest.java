class Solution {
    public int getSecondLargest(int[] arr) {
        // code here
        int maxy=arr[0];
        int secondMax=-1;
        for(int i=1;i<arr.length;i++){
            if(arr[i]>maxy){
                secondMax=maxy;
                maxy=Math.max(maxy,arr[i]);
            }
            else{
                if(arr[i]!=maxy)
                secondMax=Math.max(secondMax,arr[i]);
            }
        }
        return secondMax;
    }
}