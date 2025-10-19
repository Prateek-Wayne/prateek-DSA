class Solution {
    public int numSubarraysWithSum(int[] nums, int k) {
        int count = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int total = 0;
        mp.put(0, 1);
        for (int i : nums) {
            total += i;
            count += mp.getOrDefault(total - k, 0);
            mp.put(total, mp.getOrDefault(total, 0) + 1);
        }
        return count;
    }
}