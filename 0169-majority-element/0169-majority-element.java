class Solution {
    public int majorityElement(int[] nums) {
        int ele=nums[0];
        int count=1;
        for(int i:nums){
            if(i==ele)
                count++;
            else{
                if(i!=ele)
                    count--;
                if(count==0){
                    ele=i;
                    count=1;
                }
            }
        }
        return ele;
    }
}