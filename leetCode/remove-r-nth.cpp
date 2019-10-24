//LeetCode: 19
//2019-10-19
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode* blankHead = new ListNode(0);
        blankHead->next = head;
        ListNode* left = blankHead;
        ListNode* right = head; 
        for(int i= 0; i < n-1; i++){
            right = right->next;
        }
        while(right->next){
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;
        ListNode* ret = blankHead->next;
        delete blankHead;
        return ret;
    }
};