class Solution {
  public int findFinalValue(int[] nums, int original) {
        Set<Integer> st = new HashSet<>();
        for (int i : nums) {
            st.add(i);
        }
        while (st.contains(original))
            original = original * 2;
        return original;
    }
}