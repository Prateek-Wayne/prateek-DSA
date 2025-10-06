// User function Template for Java

class Solution {
   public static int kthSmallest(int[] arr, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i = 0; i < arr.length; i++) {
            maxHeap.add(arr[i]);
            if (maxHeap.size() > k)
                maxHeap.poll();
        }
        return maxHeap.peek();

    }
}
