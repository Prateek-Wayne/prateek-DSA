/*
class Node {
    int data;
    Node next;
    Node prev;

    Node(int data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
*/
class Solution {
   public Node reverse(Node head) {
        Node temp = head;
        Node back = null;
        if (temp == null)
            return temp;
        while (temp != null) {
            back = temp;
            Node front = temp.next;
            temp.next = temp.prev;
            temp.prev = front;
            temp = front;
        }
        return back;

        // code here

    }
}