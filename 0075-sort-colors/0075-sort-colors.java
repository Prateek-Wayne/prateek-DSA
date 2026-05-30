class Solution {
    public void sortColors(int[] nums) {
        int o=0;
        int z=0;
        int t=nums.length-1;
        while(o<=t){
            if(nums[o]==2){
                int temp=nums[o];
                nums[o]=nums[t];
                nums[t]=temp;
                t--;
            }
            else if(nums[o]==0){
                int temp=nums[o];
                nums[o]=nums[z];
                nums[z]=temp;
                z++;
                o++;
            }
            else{
                o++;
            }
        }
        return;
    }
}