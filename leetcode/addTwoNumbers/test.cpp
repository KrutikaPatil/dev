#include "addTwo.hpp"





int main(int argc, char const *argv[])
{
    ListNode* odd = new ListNode(1);
    ListNode* iter = odd;
    for (int i = 1; i < 5; i++)
    {
        iter->next = new ListNode(2 * i + 1);
        iter = iter->next;
    }
    
    ListNode* even = new ListNode(2);
    iter = even;
    for (int i = 1; i < 4; i++)
    {
        iter->next = new ListNode(2 * i + 2);
        iter = iter->next;
    }

    print(odd);
    print(even);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(odd, even);

    print(result);

    return 0;
}
