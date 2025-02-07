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
ListNode *oddEvenList(ListNode *head)
{
     if(!head)
        return NULL;
     if (!head->next)
        return head;
   

    ListNode *odd = head, *even = head->next, *even2 = head->next;
    while (odd && even->next)
    {
        odd->next = odd->next->next;
        if (odd->next)
            odd = odd->next;
        even->next = even->next->next;
        if (even->next)
            even = even->next;
    }
    odd->next = even2;
    return head;
}
};