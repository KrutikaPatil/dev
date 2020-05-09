#include <stdio.h>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print(ListNode* lst){
    ListNode* iter = lst;
    while (true)
    {
        if (iter != nullptr)fprintf(stdout, "%d->", iter->val);
        else break;
        iter = iter->next;
    }
    fprintf(stdout, "\n");
}


class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int a = 0, b = 0;

        if (l1 != nullptr)
        {
            a = l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            b = l2->val;
            l2 = l2->next;
        }

        int temp = a + b;
        ListNode *result = new ListNode(temp % 10);
        int carry = temp / 10;
        ListNode* iter = result;

        while ((l1 != nullptr) | (l2 != nullptr))
        {
            a = 0;
            b = 0;

            if (l1 != nullptr)
            {
                a = l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                b = l2->val;
                l2 = l2->next;
            }

            temp = a + b + carry;

            iter->next = new ListNode(temp % 10);
            carry = temp / 10;
            iter = iter->next;
        }
        if (carry > 0) iter->next = new ListNode(carry);
            
        return result;
    }
};
