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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *temp1 = headA, *temp2 = headB;
   while (temp1 != temp2)
    {
        // When temp1 reaches end of list A, switch to headB
        temp1 = temp1 == nullptr ? headB : temp1->next;
        
        // When temp2 reaches end of list B, switch to headA
        temp2 = temp2 == nullptr ? headA : temp2->next;
    }
    
    // Return the intersection point, or nullptr if there is none
    return temp1;
}
};