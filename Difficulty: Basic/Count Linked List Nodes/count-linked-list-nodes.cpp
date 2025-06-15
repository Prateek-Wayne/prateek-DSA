/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    int helper(struct Node *temp){
        if(temp){
            return 1+helper(temp->next);
        }
        return 0;
    }
    int getCount(struct Node* head) {
    return helper(head);
    
    }
};