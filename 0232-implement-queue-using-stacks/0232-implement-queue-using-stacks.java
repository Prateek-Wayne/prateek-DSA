class MyQueue {

    Stack<Integer> stack1;
    Stack<Integer> stack2;

    public MyQueue() {
        this.stack1 = new Stack<>();
        this.stack2 = new Stack<>();
    }

    public void push(int x) {
        stack1.add(x);
    }

    public int pop() {
        if (!empty()) {
            int n = stack1.size();

            for (int i = 0; i < n - 1; i++) {
                stack2.add(stack1.pop());
            }
            int ans = stack1.pop();
            while (!stack2.isEmpty()) {
                stack1.add(stack2.pop());
            }
            return ans;
        }
        return -1;
    }

    public int peek() {
        if (!empty()) {
            int n = stack1.size();

            for (int i = 0; i < n - 1; i++) {
                stack2.add(stack1.pop());
            }
            int ans = stack1.peek();
            stack2.add(stack1.pop());
            while (!stack2.isEmpty()) {
                stack1.add(stack2.pop());
            }
            return ans;
        }
        return -1;
    }

    public boolean empty() {
        return stack1.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */