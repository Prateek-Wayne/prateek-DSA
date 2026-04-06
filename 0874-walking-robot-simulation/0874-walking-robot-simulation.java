class Solution {
 public int robotSim(int[] commands, int[][] obstacles) {
        HashSet<String> st = new HashSet<>();
        for (int[] arr : obstacles) {
            st.add(arr[0] + "|" + arr[1]);
        }
        int x = 0;
        int y = 0;
        int ans = 0;
        int[][] dir = new int[][] { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
        int d = 0;
        for (int c : commands) {
            if (c >= 0) {
                for (int i = 0; i < c; i++) {
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];
                    if (!st.contains(nx + "|" + ny)) {
                        x = nx;
                        y = ny;
                        ans = Math.max(ans, x * x + y * y);
                    } else
                        break;
                }
            } else if (c == -1) {
                d = (d + 1) % 4;
            } else if (c == -2) {
                d = (d + 3) % 4;
            }
        }

        return ans;
    }
}