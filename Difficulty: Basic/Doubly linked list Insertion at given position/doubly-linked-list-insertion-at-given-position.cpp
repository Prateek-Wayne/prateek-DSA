/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node *temp=head;
        while(pos){
            pos--;
            temp=temp->next;
        }
        Node *newNode=new Node(data);
        Node *second=temp->next;
        if(second){
            newNode->prev=temp;
            temp->next=newNode;
            second->prev=newNode;
            newNode->next=second;
        }
        else
        {
            newNode->prev=temp;
            temp->next=newNode;
        }
        return head;
    }
};