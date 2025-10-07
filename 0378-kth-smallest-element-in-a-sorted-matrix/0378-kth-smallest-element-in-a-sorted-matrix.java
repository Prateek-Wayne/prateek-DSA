class Solution {
  public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int[] i : matrix) {
            for (int j : i) {
                maxHeap.add(j);
                if (maxHeap.size() > k)
                    maxHeap.poll();
            }
        }
        return maxHeap.poll();
    }
}