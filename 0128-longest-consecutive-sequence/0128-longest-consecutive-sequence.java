class Solution {
  public int longestConsecutive(int[] nums) {
        HashSet<Integer> st = new HashSet<>();
        for (int i : nums)
            st.add(i);
        int ans = 0;
        for (Integer i : st) {
            if (!st.contains(i - 1)) {
                int count = 1;
                Integer curr = i;
                while (st.contains(curr + 1)) {
                    curr = curr + 1;
                    count++;
                }
                ans = Math.max(ans, count);
            }
        }
        return ans;
    }
}