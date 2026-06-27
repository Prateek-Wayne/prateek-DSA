class Solution {
    public int maximumLength(int[] nums) {
        HashMap<Long, Long> mp = new HashMap<>();
        int ones = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1)
                ones++;
            else
                mp.put(1L * nums[i], mp.getOrDefault(nums[i] * 1L, 0L) + 1);
        }
        int ans = 0;
        if (ones != 0) {
            // even..
            if (ones % 2 == 0)
                ans = ones - 1;
            else
                ans = ones;
        }
        for (int i = 0; i < nums.length; i++) {
            long ele = 1L * nums[i];
            int count = 0;
            while (mp.containsKey(ele) && mp.get(ele) > 1) {
                count += 2;
                ele = ele * ele;
            }
            if (mp.containsKey(ele) && mp.get(ele) == 1) {
                count++;
            } else {
                count--;
            }
            ans = Math.max(count, ans);
        }
        return ans;

    }
}