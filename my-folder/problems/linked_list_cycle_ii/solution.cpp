/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectLoop(ListNode *head)
    {
        ListNode *p,*q;
        p=q=head;
        while(q!=NULL && q->next!=NULL)
        {
            p=p->next;
            q=q->next->next;
            if(p==q)
                return p;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        ListNode *meet=detectLoop(head);
        ListNode *temp=head;
        if(meet!=NULL&&temp!=NULL){
        while(temp!=meet)
        {
            temp=temp->next;
            meet=meet->next;
        }
        return temp;
      //          while(temp!=NULL||meet!=NULL)
      //   {
      //       if(temp==meet)
      //           return temp;
      //       temp=temp->next;
      //       meet=meet->next;
      //   }
      // // return NULL;
      //   return NULL;
        }

        return NULL;
    }
};