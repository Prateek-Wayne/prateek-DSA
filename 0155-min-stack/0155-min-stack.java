class Pair {
    int first;
    int second;

    Pair(int a, int b) {
        this.first = a;
        this.second = b;
    }
}
class MinStack {
    List<Pair> arr;

    public MinStack() {
        this.arr = new ArrayList<>();
    }

    public void push(int val) {
        if (arr.isEmpty()) {
            Pair p = new Pair(val, val);
            arr.add(p);
        } else {
            int last = arr.get(arr.size() - 1).second;
            Pair p = new Pair(val, Math.min(val, last));
            arr.add(p);
        }
    }

    public void pop() {
        int last = arr.get(arr.size() - 1).first;
        arr.remove(arr.size() - 1);

    }

    public int top() {
        int last = arr.get(arr.size() - 1).first;
        return last;

    }

    public int getMin() {
        int min = arr.get(arr.size() - 1).second;
        return min;

    }
}