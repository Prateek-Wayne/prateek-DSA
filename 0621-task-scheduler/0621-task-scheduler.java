class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] mp = new int[26];
        for (char c : tasks) {
            mp[c - 'A']++;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> b - a);
        for (int i : mp) {
            if (i > 0)
                pq.add(i);
        }
        int ansTime = 0;
        while (!pq.isEmpty()) {
            List<Integer> temp = new ArrayList<>();
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.isEmpty()) {
                    int top = pq.poll();
                    top--;
                    temp.add(top);
                }
            }
            for (int i : temp) {
                if (i > 0) {
                    pq.add(i);
                }
            }
            if (pq.isEmpty()) {
                ansTime += temp.size();
            } else {
                ansTime += n + 1;
            }

        }
        return ansTime;
    }
}