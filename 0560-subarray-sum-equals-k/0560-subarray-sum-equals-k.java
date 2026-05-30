class Solution {
    public int subarraySum(int[] nums, int k) {
        int sum = 0;
        int count = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);
 for (int i : nums) {
            sum += i;
            int req = sum - k;
            count += mp.getOrDefault(req, 0);
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }
        return count;
    }
}