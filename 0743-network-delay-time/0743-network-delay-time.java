class Solution {
 public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Integer[]>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int edges[] : times) {
            int from = edges[0];
            int to = edges[1];
            int w = edges[2];
            adj.get(from).add(new Integer[] { to, w });
        }

        PriorityQueue<Integer[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        Integer[] parent = new Integer[n + 1];
        Integer[] result = new Integer[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            result[i] = Integer.MAX_VALUE;
        }
        parent[k] = k;
        result[k] = 0;
        pq.add(new Integer[] { 0, k });
        while (!pq.isEmpty()) {
            Integer[] top = pq.poll();
            int src = top[1];
            int dist = top[0];
            for (Integer[] v : adj.get(src)) {
                int nei = v[0];
                int w = v[1];
                if (result[nei] > w + dist) {
                    result[nei] = w + dist;
                    parent[nei] = src;
                    pq.add(new Integer[] { w + dist, nei });
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            System.out.println(result[i]);
            if (result[i] == Integer.MAX_VALUE)
                return -1;
            ans = Math.max(ans, result[i]);
        }
        return ans;
    }
}