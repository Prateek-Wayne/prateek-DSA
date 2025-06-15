/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        if(x==1)
        {head=head->next;
         return head;
        }
        int count=1;
        Node *first=head;
        Node *second=first;
        first=first->next;
        count++;
        while(first){
            if(count==x){
                second->next=second->next->next;
            }
            count++;
            first=first->next;
            second=second->next;
        }
        return head;
        
    }
};