/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}

*/

class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        
        Node *temp=head,*prev=NULL;
        while(temp){
            Node *front=temp->next;
            // front->next=temp;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
};