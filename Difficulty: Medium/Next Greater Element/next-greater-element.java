class Solution {
    public static ArrayList<Integer> nextLargerElement(int[] arr) {
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        ArrayList<Integer> ans = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            ans.add(-1);
        }
        st.add(arr[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            while (!st.isEmpty() && st.peek() <= arr[i]) {
                st.pop();
            }
            if (st.isEmpty()) {
                ans.set(i, -1);
            } else {
                ans.set(i, st.peek());
            }

            st.add(arr[i]);
        }
        return ans;
    }
}