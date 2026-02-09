class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {

    private static int[] nse(int[] arr) {
        Stack<Pair> st = new Stack<>();
        int n = arr.length;
        int[] nse = new int[n];
        Pair p = new Pair(arr[n - 1], n - 1);
        nse[n - 1] = n;
        st.add(p);
        for (int i = n - 2; i >= 0; i--) {
            if (st.peek().first < arr[i]) {
                nse[i] = st.peek().second;
            } else {
                while (!st.isEmpty() && st.peek().first >= arr[i])
                    st.pop();
                if (st.isEmpty()) {
                    nse[i] = n;
                } else if (st.peek().first < arr[i]) {
                    nse[i] = st.peek().second;
                }
            }
            Pair newPair = new Pair(arr[i], i);

            st.add(newPair);
        }
        return nse;
    }

    private static int[] psee(int[] arr) {
        Stack<Pair> st = new Stack<>();
        int n = arr.length;
        int[] psee = new int[n];
        psee[0] = -1;
        Pair p = new Pair(arr[0], 0);
        st.add(p);
        for (int i = 1; i < n; i++) {
            if (st.peek().first <= arr[i]) {
                psee[i] = st.peek().second;
            } else {
                while (!st.empty() && st.peek().first > arr[i]) {
                    st.pop();
                }
                if (st.isEmpty()) {
                    psee[i] = -1;
                } else if (st.peek().first <= arr[i]) {
                    psee[i] = st.peek().second;
                }
            }
            Pair newPair = new Pair(arr[i], i);
            st.add(newPair);
        }
        return psee;
    }

    public static int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int modulo = (int) (1e9 + 7);
        int[] nse = nse(arr);
        int[] pse = psee(arr);
        int total = 0;
    for (int i = 0; i < n; i++) {
        long contribution = ((long)arr[i] * (nse[i] - i) * (i - pse[i])) % modulo;
        total = (total +(int) contribution) % modulo;
    }
        return total;
    }

}