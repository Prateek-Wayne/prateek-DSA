/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
      
        if(head==NULL)
            return NULL;
        else{
        ListNode *temp1=head;
        ListNode *temp2=head;
        ListNode *Odd = head;
        ListNode *even=head;
        even=head->next;
        temp2=head->next;
        while(temp2 && temp2->next)
       {
           temp1->next=temp1->next->next;
           temp1=temp1->next;
           temp2->next=temp2->next->next;
           temp2=temp2->next;
       }
        temp1->next=even;
        return head;
        }
    }
};