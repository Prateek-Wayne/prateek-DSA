class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans=new ArrayList<Boolean>();
        long result=0;
        for(int i=0;i<nums.length;i++){
            result=(result*2+nums[i])%5;
            ans.add(result==0);
        }
        return ans;
        
    }
}