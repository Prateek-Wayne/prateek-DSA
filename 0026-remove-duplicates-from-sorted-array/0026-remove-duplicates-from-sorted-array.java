class Solution {
    public int removeDuplicates(int[] nums) {
        int n=nums.length;
        int prev=0;
        int next=1;
        int count=0;
        while(next<n){

            if(nums[prev]!=nums[next]){
                prev++;
                int temp=nums[prev];
                nums[prev]=nums[next];
                nums[next]=temp;
                count++;
            }
            next++;
        }
        return count+1;
    }
}