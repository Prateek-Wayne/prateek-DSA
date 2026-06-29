
class CustomStack {

    List<Integer> st;
    int maxSize;
    int size;

    public CustomStack(int maxSize) {
        this.st = new ArrayList<>();
        this.maxSize = maxSize;
        this.size = 0;

    }

    public void push(int x) {
        if (size >= maxSize)
            return;
        st.add(x);
        size++;
    }

    public int pop() {
        if (size == 0)
            return -1;
        size--;
        return st.removeLast();

    }

    public void increment(int k, int val) {
        for (int i = 0; i < Math.min(k, size); i++)
            st.set(i, st.get(i) + val);
        return;
    }
}