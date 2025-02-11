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
  
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *temp1 = l1, *temp2 = l2, *prev1 = nullptr, *prev2 = nullptr;
    int carry = 0;
    while (temp1 && temp2)
    {
        prev1 = temp1;
        prev2 = temp2;
        temp1->val = temp1->val + temp2->val + carry;
        temp2->val = temp1->val;
        carry = temp1->val / 10;
        if (temp1->val > 9)
        {
            carry = temp1->val / 10;
            temp1->val = temp1->val % 10;
            temp2->val = temp2->val % 10;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (temp1)
    {
        while (temp1)
        {
            prev1 = temp1;
            temp1->val += carry;
            carry = 0;
            if (temp1->val > 9)
            {
                carry = temp1->val / 10;
                temp1->val = temp1->val % 10;
            }
            temp1 = temp1->next;
        }
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            prev1->next = newNode;
        }
        return l1;
    }
    else if (temp2)
    {
        while (temp2)
        {
            prev2=temp2;
            temp2->val += carry;
            carry = 0;
            if (temp2->val > 9)
            {
                carry = temp2->val / 10;
                temp2->val = temp2->val % 10;
            }
            temp2 = temp2->next;
        }
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            prev2->next = newNode;
        }
       
        return l2;
    }
 if(carry)
        {
            ListNode *newNode = new ListNode(carry);
            prev1->next=newNode;
        }
    return l1;
}
};