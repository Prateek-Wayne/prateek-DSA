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
 public void reorderList(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode temp = slow;
        slow = slow.next;
        temp.next = null;
        // reverse....
        ListNode prev = null;
        ListNode curr = slow;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        ListNode head2 = prev;
        ListNode head1 = head;
        while (head1 != null && head2 != null) {
            ListNode head1Next = head1.next;
            head1.next = head2;
            ListNode head2Next = head2.next;
            head2.next = head1Next;
            head1 = head1Next;
            head2 = head2Next;
        }
    }
}