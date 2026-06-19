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
class Solution {
public ListNode removeNthFromEnd(ListNode head, int n) {
    if (head == null) return head;

    ListNode temp = head;
    int length = 0;

    while (temp != null) {
        temp = temp.next;
        length++;
    }

    int index = length - n;

    // 🔥 edge case: remove head
    if (index == 0) {
        return head.next;
    }

    temp = head;
    for (int i = 0; i < index - 1; i++) {
        temp = temp.next;
    }

    temp.next = temp.next.next;

    return head;
}
}