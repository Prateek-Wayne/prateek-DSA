class Solution {
    public int[] rearrangeArray(int[] nums) {
        int p=0;
        int n=1;
        int size=nums.length;
        int[] newArray=new int[size];
        for(int i=0;i<size;i++){
            if(nums[i]>=0){
                newArray[p]=nums[i];
                p+=2;
            }else{
                newArray[n]=nums[i];
                n+=2;
            }
        }
        return newArray;
    }
}