class myQueue {
    List<Integer> arr = new ArrayList<>();
    int size;

    // Constructor
    public myQueue(
            int n) {
        // Define Data Structures
        this.size = n;
    }

    public boolean isEmpty() {
        // Check if queue is empty
        return arr.size() == 0;
    }

    public boolean isFull() {
        return arr.size() == size;
    }

    public void enqueue(int x) {
        // Enqueue
        if (!isFull()) {
            arr.add(x);
        }
    }

    public void dequeue() {
        // Dequeue
        if (!isEmpty()) {
            arr.remove(0);
        }
    }

    public int getFront() {
        // Get front element
        if (!isEmpty())
            return arr.get(0);
        return -1;
    }

    public int getRear() {
        // Get last element
        if (!isEmpty())
            return arr.get(arr.size() - 1);
        return -1;
    }
}