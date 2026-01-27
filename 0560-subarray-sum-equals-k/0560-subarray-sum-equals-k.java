class Solution {
    public int subarraySum(int[] nums, int k) {
            HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);
        int ans = 0;
        int sum = 0;
        for (int i : nums) {
            sum += i;
            int req = sum-k;
            ans+=mp.getOrDefault(req, 0);
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }
        return ans;

    }
}