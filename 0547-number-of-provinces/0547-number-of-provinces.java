class Solution {
 void dfs(List<List<Integer>> adj, boolean[] vis, int curr) {
        if (vis[curr])
            return;
        vis[curr] = true;
        for (Integer i : adj.get(curr)) {
            if (!vis[i]) {
                dfs(adj, vis, i);
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        // adj
        int V = isConnected.length;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < isConnected[i].length; j++) {
                if (i != j) {
                    if (isConnected[i][j] == 1) {
                        adj.get(i).add(j);
                        adj.get(j).add(i);
                    }
                }
            }
        }
        boolean[] vis = new boolean[V];
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(adj, vis, i);
            }
        }
        return count;
    }
}