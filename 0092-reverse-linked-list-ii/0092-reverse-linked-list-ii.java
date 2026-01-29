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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode prev = dummy;
        ListNode temp = head;
        for (int i = 0; i < left - 1; i++) {
            prev = prev.next;
            temp = temp.next;
        }
        ListNode prevToFirstHead = prev;
        ListNode firstHead = temp;
        temp = head;
        for (int i = 0; i < right - 1; i++) {
            temp = temp.next;
        }
        ListNode secondHead = temp;
        ListNode nextToSecondHead = secondHead.next;
        prevToFirstHead.next = null;
        secondHead.next = null;
        prev = null;
        temp = firstHead;
        while (temp != null) {
            ListNode next = temp.next;
            temp.next = prev;
            prev = temp;
            temp = next;
        }
        prevToFirstHead.next = prev;
        firstHead.next = nextToSecondHead;
        return dummy.next;
    }
}