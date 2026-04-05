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
 public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode temp1 = l1;
        ListNode temp2 = l2;
        ListNode ans = new ListNode(0);
        ListNode curr = ans;
        int carry = 0;

        while (temp1 != null && temp2 != null) {
            int val1 = temp1.val;
            int val2 = temp2.val;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode newNode = new ListNode(sum);
            curr.next = newNode;
            curr = curr.next;
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        while (temp1 != null) {
            int val1 = temp1.val;
            int sum = val1 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode newNode = new ListNode(sum);
            curr.next = newNode;
            curr = curr.next;
            temp1 = temp1.next;
        }
        while (temp2 != null) {
            int val1 = temp2.val;
            int sum = val1 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode newNode = new ListNode(sum);
            curr.next = newNode;
            curr = curr.next;
            temp2 = temp2.next;
        }
        if (carry != 0) {
            ListNode newNode = new ListNode(carry);
            carry = 0;
            curr.next = newNode;
            curr = curr.next;
        }
        return ans.next;
    }
}