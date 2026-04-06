
class DLL {
    int val1;
    int val2;
    DLL prev;
    DLL next;

    DLL(int val1, int val2) {
        this.val1 = val1;
        this.val2 = val2;
        this.prev = null;
        this.next = null;
    }

    DLL() {
        this.val1 = -1;
        this.val2 = -1;
        this.prev = null;
        this.next = null;
    }
}

public class LRUCache {
    DLL head = new DLL();
    DLL tail = new DLL();
    int capacity;
    HashMap<Integer, DLL> mp = new HashMap<>();

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }

    public void deleteNode(DLL node) {
        DLL prevNode = node.prev;
        DLL nextNode = node.next;
        prevNode.next = prevNode.next.next;
        nextNode.prev = nextNode.prev.prev;
        node.prev = null;
        node.next = null;
        return;
    }

    public void addToHead(DLL curr) {
        DLL nextToHead = head.next;
        head.next = curr;
        curr.prev = head;
        curr.next = nextToHead;
        nextToHead.prev = curr;
        return;
    }

    public int get(int key) {
        if (mp.containsKey(key)) {
            DLL existingNode = mp.get(key);
            deleteNode(existingNode);
            addToHead(existingNode);
            return existingNode.val2;
        } else {
            return -1;
        }
    }

    public void put(int key, int value) {
        if (mp.containsKey(key)) {
            DLL curr = mp.get(key);
            curr.val2 = value;
            deleteNode(curr);
            addToHead(curr);
            return;
        } else if (mp.size() < capacity) {
            DLL newNode = new DLL(key, value);
            addToHead(newNode);
            mp.put(key, newNode);
            return;
        } else {
            // delete last node...
            DLL prevToHead = tail.prev;
            mp.remove(prevToHead.val1);
            deleteNode(prevToHead);
            DLL newNode = new DLL(key, value);
            mp.put(key, newNode);
            addToHead(newNode);
            return;
        }
    }
}