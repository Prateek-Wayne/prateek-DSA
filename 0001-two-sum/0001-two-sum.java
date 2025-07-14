class Solution {
  public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            mp.put(nums[i], i);
        }
        int[] ans = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int toFind = target - nums[i];
            if (mp.containsKey(toFind) && mp.get(toFind) != i) {
                int first = i;
                int second = mp.get(toFind);
                return new int[] { first, second };
            }
        }
        return ans;
    }
}