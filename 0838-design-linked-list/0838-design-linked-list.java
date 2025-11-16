class Node {
    int val;
    Node next;

    Node(int x) {
        this.val = x;
        next = null;
    }
}

class MyLinkedList {
    Node head;

    public MyLinkedList() {
        head = null;
    }

    public int get(int index) {
        Node temp = head;
        int count = 0;
        while (temp != null && count < index) {
            temp = temp.next;
            count++;
        }
        if (temp != null && count == index)
            return temp.val;
        return -1;
    }

    public void addAtHead(int val) {
        Node newNode = new Node(val);
        newNode.next = head;
        head = newNode;
    }

    public void addAtTail(int val) {
        if (head == null) {
            addAtHead(val);
            return;
        }
        Node temp = head;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new Node(val);
    }

    public void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        // Handle empty list
        if (head == null)
            return;

        Node temp = head;
        int count = 0;

        // Traverse to position BEFORE insertion point
        while (temp != null && count < index - 1) {
            temp = temp.next;
            count++;
        }

        // If valid position
        if (temp != null) {
            Node newNode = new Node(val);
            newNode.next = temp.next;
            temp.next = newNode;
        }
    }

    public void deleteAtIndex(int index) {
        if (head == null)
            return;

        if (index == 0) {
            head = head.next;
            return;
        }

        Node temp = head;
        int count = 0;

        // Traverse to position BEFORE deletion point
        while (temp != null && count < index - 1) {
            temp = temp.next;
            count++;
        }

        // Check if node exists at index
        if (temp != null && temp.next != null) {
            temp.next = temp.next.next;
        }
    }
}
