class Solution {
    public int majorityElement(int[] nums) {
        int ele=nums[0];
        int sum=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]==ele){
                sum++;
            }
            else{
                if(sum==0){
                    ele=nums[i];
                    sum++;
                }
                sum--;
            }
        }
        return ele;
    }
}