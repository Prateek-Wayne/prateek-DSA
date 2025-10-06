class Solution {
    public static int minCost(int[] arr) {
        // code here
                PriorityQueue<Integer> minHeap = new PriorityQueue<>();
     int ans = 0;
        for (int i : arr) {
            minHeap.add(i);
        }
        while (minHeap.size() > 1) {
            int a = minHeap.poll();
            int b = minHeap.poll();
            ans += a + b;
            minHeap.add(a + b);
        }
        return ans;

    }
}