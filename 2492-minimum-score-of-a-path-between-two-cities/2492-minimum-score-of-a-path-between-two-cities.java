class Solution {
void dfs(List<List<int[]>> adj, int u, boolean[] vis, int[] min) {
        vis[u] = true;
        for (int[] v : adj.get(u)) {
            int vv = v[0];
            int d = v[1];
            min[0] = Math.min(min[0], d);
            if (!vis[vv]) {
                dfs(adj, vv, vis, min);
            }
        }
    }

    public int minScore(int n, int[][] roads) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] r : roads) {
            int u = r[0];
            int v = r[1];
            int d = r[2];
            adj.get(u).add(new int[] { v, d });
            adj.get(v).add(new int[] { u, d });
        }
        boolean[] vis = new boolean[n + 1];

        int[] min = new int[] { Integer.MAX_VALUE };
        dfs(adj, n, vis, min);
        return min[0];
    }
}