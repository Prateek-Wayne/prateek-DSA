class Solution {
    public int[] nextGreaterElements(int[] nums) {
        List<Integer> arr = new ArrayList<>();
        int n = nums.length * 2;
        for (int num : nums) {
            arr.add(num);
        }
        for (int num : nums) {
            arr.add(num);
        }
        Stack<Integer> st = new Stack<>();
        int[] ans = new int[n];
        ans[n - 1] = -1;
        st.add(arr.get(n - 1));
        for (int i = n - 2; i >= 0; i--) {
            while (!st.isEmpty() && st.peek() <= arr.get(i)) {
                st.pop();
            }
            if (st.isEmpty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.peek();
            }
            st.add(arr.get(i));
        }
        return Arrays.copyOfRange(ans, 0, n/2);
    }
}