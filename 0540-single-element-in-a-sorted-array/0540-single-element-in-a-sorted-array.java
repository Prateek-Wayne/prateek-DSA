class Solution {
    public int singleNonDuplicate(int[] nums) {
        Integer xor=null;
        for(int i:nums){
            if(xor==null){
                xor=i;
            }
            else{
                xor=xor^i;
            }
        }
        return xor;
    }
}