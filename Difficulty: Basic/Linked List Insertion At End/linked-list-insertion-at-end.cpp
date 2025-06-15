/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        if(!head){
            Node *newNode=new Node(x);
            return newNode;
        }
        Node *temp=head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=new Node(x);
        temp=temp->next;
        temp->next=NULL;
        return head;
    }
};