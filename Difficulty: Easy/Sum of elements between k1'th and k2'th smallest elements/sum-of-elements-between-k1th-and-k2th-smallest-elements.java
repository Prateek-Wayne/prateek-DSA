// User function Template for Java

class Solution {
    private static long kthElement(long A[], long K) {
        PriorityQueue<Long> maxHeapk = new PriorityQueue<>((a, b) -> Long.compare(b, a));
        for (int i = 0; i < A.length; i++) {
            maxHeapk.add(A[i]);
            if (maxHeapk.size() > K)
                maxHeapk.poll();
        }
        return maxHeapk.peek();

    }

    public static long sumBetweenTwoKth(long A[], long N, long K1, long K2) {
        // Your code goes here
        long k1Smallest = kthElement(A, K1);
        long k2Smallest = kthElement(A, K2);
        long sum = 0;
        for (long i : A) {
            if (i > k1Smallest && i < k2Smallest)
                sum += i;
        }
        return sum;

    }
}
