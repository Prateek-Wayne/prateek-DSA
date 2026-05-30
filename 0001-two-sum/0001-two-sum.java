class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        mp.put(nums[0],0);
        for(int i=1;i<nums.length;i++){
            int required=target-nums[i];
            if(mp.get(required)!=null){
                return new int[]{mp.get(required),i};
            }
            mp.put(nums[i],i);
        }
        return new int[]{};
    }
}