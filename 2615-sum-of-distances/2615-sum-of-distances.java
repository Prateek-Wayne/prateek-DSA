class Solution {
    public long[] distance(int[] nums) {
        int n = nums.length;
        long[] ans = new long[n];
        HashMap<Integer, Long> freq = new HashMap<>();
        HashMap<Integer, Long> sigma = new HashMap<>();
        for (int i = 0; i < n; i++) {
            long freqOfi = freq.getOrDefault(nums[i], 0l);
            long sigmaOfi = sigma.getOrDefault(nums[i], 0l);
            long sum = freqOfi * i - sigmaOfi;
            ans[i] = sum;
            freq.put(nums[i], freq.getOrDefault(nums[i], 0l) + 1);
            sigma.put(nums[i], sigma.getOrDefault(nums[i], 0l) + i);
        }
        freq = new HashMap<>();
        sigma = new HashMap<>();
        for (int i = n - 1; i >= 0; i--) {
            long freqOfi = freq.getOrDefault(nums[i], 0l);
            long sigmaOfi = sigma.getOrDefault(nums[i], 0l);
            long sum = sigmaOfi - freqOfi * i;
              ans[i] = ans[i] + sum;
            freq.put(nums[i], freq.getOrDefault(nums[i], 0l) + 1);
            sigma.put(nums[i], sigma.getOrDefault(nums[i], 0l) + i);
        }

        return ans;
    }
}