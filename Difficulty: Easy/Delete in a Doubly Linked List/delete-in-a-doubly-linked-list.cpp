/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
Node *deleteNode(Node *head, int x)
{
     if (x == 1)
    {
        if (head->next)
        {
            head = head->next;
            head->prev = NULL;
            return head;
        }
        return NULL;
    }
    Node *temp = head;
    for (int i = 1; i < x; ++i)
    {
        temp = temp->next;
    }
    temp->prev->next=temp->next;
    if(temp->next)
        temp->next->prev=temp->prev;
    return head;
}
};