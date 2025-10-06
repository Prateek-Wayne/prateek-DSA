class Solution {
   public void nearlySorted(int[] arr, int k) {
        // code here
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        for (int i = 0; i < arr.length; i++) {
            minHeap.add(arr[i]);
            if (minHeap.size() > k) {
                arr[i - k] = minHeap.poll();
            }
        }
        int lastIndex = arr.length - k;
        while (lastIndex < arr.length) {
            arr[lastIndex] = minHeap.poll();
            lastIndex++;
        }
        return;
    }
}
