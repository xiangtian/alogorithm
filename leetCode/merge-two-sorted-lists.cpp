//LeetCode: 21
// 2019-10-17
#include<iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* ret = new ListNode(0);
        ListNode* current = ret;
        while(h1 && h2){
            if (h1->val < h2->val){
                current->next = h1;
                current = current->next;
                h1 = h1->next;
            } else {
                current->next = h2;
                current = current->next;
                h2 = h2->next;
            }
        }     
        if(h1) {
            current->next = h1;
            current = current->next;
            h1 = h1->next;    
        }
        if(h2){
            current->next = h2;
            current = current->next;
            h2 = h2->next;
        }
        ListNode* r = ret->next;
        delete ret;
        return r;
    }
};