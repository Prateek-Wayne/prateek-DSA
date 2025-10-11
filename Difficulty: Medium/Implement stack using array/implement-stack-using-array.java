
class myStack {
    List<Integer> arr = new ArrayList<>();
    Integer size;

    public myStack(int n) {
        // Define Data Structures
        this.size = n;
    }

    public boolean isEmpty() {
        if (arr.size() == 0)
            return true;
        return false;
    }

    public boolean isFull() {
        // check if the stack is
        if (arr.size() == size)
            return true;
        return false;
    }

    public void push(int x) {
        // Inserts x at the top of the stack
        if (arr.size() < size)
            arr.add(x);
        else
            return;
    }

    public void pop() {
        // Removes an element from the top of the stack
        if (arr.size() > 0)
            arr.remove(arr.size() - 1);
        else
            return;
    }

    public int peek() {
        // Returns the top element of the stack
        if (arr.size() > 0)
            return arr.get(arr.size() - 1);
        else
            return -1;
    }
}