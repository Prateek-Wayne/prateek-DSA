class Solution {

    public void reverse(int[] nums,int start,int end){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
        return;
    }
    public void nextPermutation(int[] nums) {
        int golaIndex=-1;
        int n=nums.length;
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                golaIndex=i-1;
                break;
            }
        }
        if(golaIndex!=-1){
            int swapIndex=golaIndex+1;
            for(int i=n-1;i>golaIndex;i--){
                if(nums[i]>nums[golaIndex]){
                    swapIndex=i;
                    break;
                }
            }
            int temp=nums[golaIndex];
            nums[golaIndex]=nums[swapIndex];
            nums[swapIndex]=temp;
        }
        reverse(nums,golaIndex+1,n-1);


    }
}