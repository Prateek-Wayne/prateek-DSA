class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int j=0;
        boolean flag=true;
        for(int i=0;i<nums.length;i++){
            if(nums[i]==1 && flag==true){
                j=i;
                flag=false;
                continue;
            }
            if(nums[i]==1 && flag==false){
                if(i-j-1<k)
                    return false;
                j=i;
            }
        }
        return true;
    }
}