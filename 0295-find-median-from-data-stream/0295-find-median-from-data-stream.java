
class MedianFinder {

    PriorityQueue<Integer> leftMaxHeap;
    PriorityQueue<Integer> rightMinHeap;

    public MedianFinder() {
        this.leftMaxHeap = new PriorityQueue<>((a, b) -> b - a);
        this.rightMinHeap = new PriorityQueue<>();
    }

    public void addNum(int num) {
        if (leftMaxHeap.size() == 0 || num < leftMaxHeap.peek()) {
            leftMaxHeap.add(num);
        } else {
            rightMinHeap.add(num);
        }
        if (Math.abs(leftMaxHeap.size() - rightMinHeap.size()) > 1) {
            int top = leftMaxHeap.poll();
            rightMinHeap.add(top);
        } else if (leftMaxHeap.size() < rightMinHeap.size()) {
            int top = rightMinHeap.poll();
            leftMaxHeap.add(top);
        }
    }

    public double findMedian() {
        // even
        if (leftMaxHeap.size() == rightMinHeap.size()) {
            return (double) (leftMaxHeap.peek() + rightMinHeap.peek()) / 2;
        } else
            return (double) leftMaxHeap.peek();
    }
}