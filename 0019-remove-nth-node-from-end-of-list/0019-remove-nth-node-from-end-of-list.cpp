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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    if (!head)
        return NULL;

    ListNode *temp = head;
    int count = 1;
    while (temp->next)
    {
        temp = temp->next;
        count++;
    }
    int res = count - n;
    if (res == 0)
    {
        head = head->next;
        return head;
    }
    temp = head;
    while (temp)
    {
        res = res - 1;
        if (res == 0)
        {
            break;
        }
        temp = temp->next;
    }
    temp->next = temp->next->next;
    return head;
    }
};