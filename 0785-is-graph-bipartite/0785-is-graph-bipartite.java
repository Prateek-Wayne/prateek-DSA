class Solution {
    boolean dfs(List<List<Integer>> adj, Integer u, Integer[] color, int currColor) {
        color[u] = currColor;
        for (Integer v : adj.get(u)) {
            if (color[v] == null) {
                int newColor = 1 - currColor;
                boolean ans = dfs(adj, v, color, newColor);
                if (!ans)
                    return false;
            } else if (color[v] == currColor)
                return false;
        }
        return true;
    }

    public boolean isBipartite(int[][] graph) {
        List<List<Integer>> adj = new ArrayList<>();
        int V = graph.length;
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < V; i++) {
            for (int e = 0; e < graph[i].length; e++) {
                adj.get(i).add(graph[i][e]);
            }
        }
        Integer[] color = new Integer[V];
        for (int i = 0; i < V; i++) {
            if (color[i] == null) {
                boolean ans = dfs(adj, i, color, 0);
                if (!ans)
                    return false;
            }
        }
        return true;
    }
}