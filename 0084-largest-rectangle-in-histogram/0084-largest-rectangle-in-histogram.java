
class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
class Solution {
private int[] nse(int[] heights) {
        int n = heights.length;
        Stack<Pair> st = new Stack<>();
        int[] ans = new int[n];
        ans[n - 1] = n;
        Pair p = new Pair(heights[n - 1], n - 1);
        st.push(p);
        for (int i = n - 2; i >= 0; i--) {
            if (st.peek().first < heights[i]) {
                ans[i] = st.peek().second;
            } else {
                while (!st.empty() && st.peek().first >= heights[i]) {
                    st.pop();
                }
                if (st.isEmpty()) {
                    ans[i] = n;
                } else {
                    ans[i] = st.peek().second;
                }
            }
            Pair newP = new Pair(heights[i], i);
            st.push(newP);
        }
        return ans;
    }

    private int[] pse(int[] heights) {
        int n = heights.length;
        Stack<Pair> st = new Stack<>();
        int[] ans = new int[n];
        ans[0] = -1;
        Pair p = new Pair(heights[0], 0);
        st.add(p);
        for (int i = 1; i < n; i++) {
            if (st.peek().first < heights[i]) {
                ans[i] = st.peek().second;
            } else {
                while (!st.empty() && st.peek().first >= heights[i]) {
                    st.pop();
                }
                if (st.isEmpty()) {
                    ans[i] = -1;
                } else {
                    ans[i] = st.peek().second;
                }
            }
            Pair newP = new Pair(heights[i], i);
            st.push(newP);
        }
        return ans;
    }

    public int largestRectangleArea(int[] heights) {
        int[] nse = nse(heights);
        int[] pse = pse(heights);
        int total = 0;
        for (int i = 0; i < heights.length; i++) {
            int calculation = heights[i] * (nse[i] - pse[i] - 1);
            total = Math.max(total, calculation);
        }
        return total;
    }
}