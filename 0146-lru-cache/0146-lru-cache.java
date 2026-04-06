class DLL {
    int key;
    int val;
    DLL next;
    DLL prev;

    DLL(int key, int val) {
        this.key = key;
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class LRUCache {
    HashMap<Integer, DLL> mp = new HashMap<>();
    DLL head;
    DLL tail;
    int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new DLL(-1, -1); // dummy head
        tail = new DLL(-1, -1); // dummy tail
        head.next = tail;
        tail.prev = head;
    }

    void delete(DLL node) {
        DLL prevNode = node.prev;
        DLL nextNode = node.next;
        prevNode.next = nextNode;
        nextNode.prev = prevNode;
        node.prev = null;
        node.next = null;
    }

    void add(DLL node) {
        DLL nextTohead = head.next;
        node.next = nextTohead;
        node.prev = head;
        head.next = node;
        nextTohead.prev = node;
    }

    public int get(int key) {
        if (mp.containsKey(key)) {
            DLL d = mp.get(key);
            delete(d);
            add(d);
            return d.val;
        }
        return -1;
    }

    public void put(int key, int value) {
        if (mp.containsKey(key)) {
            // Update value and move to front
            DLL node = mp.get(key);
            node.val = value;
            delete(node);
            add(node);
        } else {
            if (mp.size() == capacity) {
                // Remove least recently used
                DLL leastUsedNode = tail.prev;
                delete(leastUsedNode);
                mp.remove(leastUsedNode.key);
            }
            DLL newNode = new DLL(key, value);
            add(newNode);
            mp.put(key, newNode);
        }
    }
}
