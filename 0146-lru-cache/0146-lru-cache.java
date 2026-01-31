
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
class LRUCache {

  int capacity = 0;
    HashMap<Integer, DLL> mp = new HashMap<>();
    DLL head = new DLL();
    DLL tail = new DLL();

    public LRUCache(
            int capacity) {
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }

    public int get(int key) {
        if (mp.containsKey(key) == false)
            return -1;
        else {
            DLL curr = mp.get(key);
            DLL prevTocurr = curr.prev;
            DLL nexTocurr = curr.next;
            prevTocurr.next = prevTocurr.next.next;
            nexTocurr.prev = nexTocurr.prev.prev;
            curr.next = null;
            curr.prev = null;
            DLL nextToHead = head.next;
            head.next = curr;
            curr.prev = head;
            curr.next = nextToHead;
            nextToHead.prev = curr;
            mp.put(key, curr);
            return curr.val2;
        }
    }

    public void put(int key, int value) {
        if (mp.containsKey(key)) {
            DLL curr = mp.get(key);
            curr.val2 = value;
            DLL prevTocurr = curr.prev;
            DLL nexTocurr = curr.next;
            prevTocurr.next = prevTocurr.next.next;
            nexTocurr.prev = nexTocurr.prev.prev;
            curr.next = null;
            curr.prev = null;
            DLL nextToHead = head.next;
            head.next = curr;
            curr.prev = head;
            curr.next = nextToHead;
            nextToHead.prev = curr;
            mp.put(key, curr);
            return;

        }
        if (mp.size() < capacity) {
            DLL newNode = new DLL(key, value);
            if (mp.size() == 0) {
                head.next = newNode;
                tail.prev = newNode;
                newNode.next = tail;
                newNode.prev = head;
            } else {
                DLL nextToHead = head.next;
                head.next = newNode;
                newNode.prev = head;
                newNode.next = nextToHead;
                nextToHead.prev = newNode;
            }
            mp.put(key, newNode);
            return;
        } else {
            DLL newNode = new DLL(key, value);

            // removing logic...
            DLL prevToTail = tail.prev;
            DLL secondprevToTail = prevToTail.prev;
            secondprevToTail.next = secondprevToTail.next.next;
            tail.prev = tail.prev.prev;
            prevToTail.next = null;
            prevToTail.prev = null;
            mp.remove(prevToTail.val1);
            DLL nextToHead = head.next;
            head.next = newNode;
            newNode.prev = head;
            newNode.next = nextToHead;
            nextToHead.prev = newNode;
            mp.put(key, newNode);
            return;
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */