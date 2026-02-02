
class MyQueue {
    Stack<Integer> s1;
    Stack<Integer> s2;

    public MyQueue() {
        s1 = new Stack<>();
        s2 = new Stack<>();
    }

    public void push(int x) {
        s1.add(x);
    }

    public int pop() {
        if (empty())
            return -1;
        int ans;
        while (s1.size() != 1) {
            s2.add(s1.pop());
        }
        ans = s1.pop();
        while (!s2.isEmpty()) {
            s1.add(s2.pop());
        }
        return ans;
    }

    public int peek() {
        if (empty())
            return -1;
        int ans;
        while (s1.size() != 1) {
            s2.add(s1.pop());
        }
        ans = s1.pop();
        s2.add(ans);
        while (!s2.isEmpty()) {
            s1.add(s2.pop());
        }
        return ans;
    }

    public boolean empty() {
        return s1.isEmpty();

    }
}