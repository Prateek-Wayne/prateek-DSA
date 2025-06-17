/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode *temp=head;
        DLLNode *newNode=NULL;
        while(temp){
            newNode=temp;
            DLLNode *front=temp->next;
            temp->next=temp->prev;
            temp->prev=front;
            temp=front;
        }
        return newNode;
        
    }
};