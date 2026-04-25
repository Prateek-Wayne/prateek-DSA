class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] inDegree = new int[numCourses];
        List<List<Integer>> adj = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();
        int[] ans = new int[numCourses];
        int course = 0;

        // ........................................................
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] arr : prerequisites) {
            adj.get(arr[1]).add(arr[0]);
            inDegree[arr[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.add(i);
            }
        }
        while (!q.isEmpty()) {
            int u = q.poll();
            ans[course] = u;
            course++;
            for (Integer v : adj.get(u)) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.add(v);
                }
            }
        }
        if (course != numCourses)
            return new int[] {};
        return ans;
    }

}