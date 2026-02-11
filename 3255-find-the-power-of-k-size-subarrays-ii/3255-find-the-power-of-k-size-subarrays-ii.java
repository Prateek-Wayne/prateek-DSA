class Solution {
    public int[] resultsArray(int[] nums, int k) {
        if (k == 1)
            return nums;
        int n = nums.length;
        List<Integer> ans = new ArrayList<>();
        int[] diff = new int[n];
        for (int i = 1; i < n; i++) {
            diff[i] = nums[i] - nums[i - 1] == 1 ? 0 : 1;
        }
        int i = 1;
        int j = 1;
        int count = 0;
        while (j < n) {
            count += diff[j];
            if (j - i + 1 == k - 1) {
                if (count > 0) {
                    ans.add(-1);
                } else {
                    ans.add(nums[j]);
                }
                count -= diff[i];
                i++;
            }
            j++;
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}