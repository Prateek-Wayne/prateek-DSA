
class MyStack {
    Queue<Integer> q1;
    Queue<Integer> q2;

    public MyStack() {
        this.q1 = new LinkedList<>();
        this.q2 = new LinkedList<>();
    }

    public void push(int x) {
        q1.add(x);

    }

    public int pop() {
        if (!empty()) {
            int size = q1.size();
            for (int i = 0; i < size - 1; i++) {
                q2.add(q1.poll());
            }
            int ans = q1.poll();
            Queue<Integer> temp = q1;
            q1 = q2;
            q2 = temp;
            return ans;
        }
        return -1;

    }

    public int top() {
        if (!empty()) {
            int size = q1.size();
            for (int i = 0; i < size - 1; i++) {
                q2.add(q1.poll());
            }
            int ans = q1.poll();
            q2.add(ans);

            Queue<Integer> temp = q1;
            q1 = q2;
            q2 = temp;
            return ans;
        }
        return -1;

    }

    public boolean empty() {
        return q1.size() == 0;
    }
}