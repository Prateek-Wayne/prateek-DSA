class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> st = new Stack<>();
        HashMap<Integer, Integer> mp = new HashMap<>();
        int size = nums2.length;
        int[] ngr = new int[size];
        ngr[size - 1] = -1;
        st.add(nums2[size - 1]);
        mp.put(nums2[size - 1], -1);
        for (int i = size - 2; i >= 0; i--) {
            if (st.peek() > nums2[i]) {
                ngr[i] = st.peek();
            } else {
                while (!st.empty() && st.peek() < nums2[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    ngr[i] = -1;
                } else {
                    ngr[i] = st.peek();
                }
            }
            mp.put(nums2[i], ngr[i]);
            st.add(nums2[i]);
        }
        int n = nums1.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = mp.get(nums1[i]);
        }
        return ans;
    }
}