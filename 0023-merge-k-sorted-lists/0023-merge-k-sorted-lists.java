/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

public class Pair {
    int first;
    ListNode second;

    Pair(int first, ListNode second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.first - b.first);
        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null) {
                Pair p = new Pair(lists[i].val, lists[i]);
                pq.add(p);
            }
        }
        ListNode dummy = new ListNode();
        ListNode temp = dummy;
        while (!pq.isEmpty()) {
            Pair top = pq.poll();
            temp.next = top.second;
            temp = temp.next;
            if (top.second.next != null) {
                Pair newPair = new Pair(top.second.next.val, top.second.next);
                pq.add(newPair);
            }
        }
        return dummy.next;
    }
}