class Solution {
    boolean dfs(List<List<Integer>> adj, boolean[] vis, boolean[] path, int curr, Stack<Integer> st) {
        vis[curr] = true;
        path[curr] = true;

        for (Integer i : adj.get(curr)) {
            if (!vis[i]) {
                if (dfs(adj, vis, path, i, st))
                    return true;
            } else if (path[i]) {
                return true;
            }
        }
        st.add(curr);
        path[curr] = false;
        return false;
    }

    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] arr : prerequisites) {
            adj.get(arr[1]).add(arr[0]);
        }
        boolean[] vis = new boolean[numCourses];
        boolean[] path = new boolean[numCourses];
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(adj, vis, path, i, st))
                    return new int[] {};
            }
        }

        int[] ans = new int[numCourses];
        int ind = 0;
        while (!st.isEmpty()) {
            ans[ind] = st.pop();
            ind++;
        }
        return ans;

    }
}