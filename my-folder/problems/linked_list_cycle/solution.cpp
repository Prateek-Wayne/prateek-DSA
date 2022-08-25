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
    bool hasCycle(ListNode *head) {
        // int c=0;
        // ListNode *temp=head;
        // while(temp)
        // {
        //    c++;
        //     temp=temp->next;
        //    if(c>10000)
        //        return true;
        // }
        // return false;
        ListNode *p=head;
        ListNode *q=head;
        while(q!=NULL && q->next!=NULL)
        {
            p=p->next;
            q=q->next->next;
            if(p==q)
                return true;
        }
        return false;
        
    }
};