class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
class Solution {
 public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] ngr = new int[n];
        Pair firstP = new Pair(temperatures[n - 1], n - 1);
        Stack<Pair> st = new Stack<>();
        st.add(firstP);
        ngr[n - 1] = firstP.second;
        for (int i = n - 2; i >= 0; i--) {
            while (!st.isEmpty() && st.peek().first <= temperatures[i])
                st.pop();
            if (st.isEmpty()) {
                ngr[i] = i;
            } else if (st.peek().first > temperatures[i]) {
                ngr[i] = st.peek().second;
            }

            Pair temp = new Pair(temperatures[i], i);
            st.add(temp);
        }
        for (int i = 0; i < n; i++) {
            ngr[i] = ngr[i] - i;
        }
        return ngr;
    }
}