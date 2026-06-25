class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer> mp=new HashMap<>();
        mp.put(0,1);
        int sum=0;
        int count=0;
        for(int i:nums){
            sum+=i;
            int req=sum-k;
            if(mp.get(req)!=null){
                count+=mp.get(req);
            }
            mp.put(sum,mp.getOrDefault(sum,0)+1);
        }
        return count;
    }
}