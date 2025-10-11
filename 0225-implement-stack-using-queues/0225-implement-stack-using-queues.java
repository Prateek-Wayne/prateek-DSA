
class MyStack {
    Queue<Integer> queue;

    public MyStack() {
        this.queue = new LinkedList<>();

    }

    public void push(int x) {
        queue.add(x);
        int size = queue.size();
        for (int i = 0; i < size - 1; i++) {
            queue.add(queue.poll());
        }

    }

    public int pop() {
        if (!empty())
            return queue.poll();
        return -1;
    }

    public int top() {
        if (!empty())
            return queue.peek();
        return -1;
    }

    public boolean empty() {
        return queue.size() == 0;
    }
}
