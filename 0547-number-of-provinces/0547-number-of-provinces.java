class Solution {
  void dfs(List<List<Integer>> adj, boolean[] vis, Integer u) {
        vis[u] = true;
        for (Integer v : adj.get(u)) {
            if (!vis[v]) {
                dfs(adj, vis, v);
            }
        }
        return;
    }

    public int findCircleNum(int[][] isConnected) {
        int m = isConnected.length;
        int n = isConnected[0].length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (isConnected[i][j] == 1) {
                        adj.get(i).add(j);
                        adj.get(j).add(i);
                    }
                }
            }
        }
        boolean[] vis = new boolean[m];
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (!vis[i]) {
                count++;
                dfs(adj, vis, i);
            }
        }
        return count;

    }
}