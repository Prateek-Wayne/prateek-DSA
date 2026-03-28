class Solution {
   boolean dfs(List<List<Integer>> adj, boolean[] vis, boolean[] path, int curr) {
        vis[curr] = true;
        path[curr] = true;
        for (Integer i : adj.get(curr)) {
            if (!vis[i]) {
                if (dfs(adj, vis, path, i))
                    return true;
            } else if (path[i])
                return true;
        }
        path[curr] = false;
        return false;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] arr : prerequisites) {
            adj.get(arr[1]).add(arr[0]);
        }
        boolean[] vis = new boolean[numCourses];
        boolean[] path = new boolean[numCourses];
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(adj, vis, path, i))
                    return false;
            }
        }
        return true;
    }
}