/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode i = headA;
        ListNode j = headB;
        while (i != j) {
            if (i == null) {
                i = headB;
            } else {
                i = i.next;
            }
            if (j == null) {
                j = headA;
            } else
                j = j.next;
        }
        return i;

    }
}