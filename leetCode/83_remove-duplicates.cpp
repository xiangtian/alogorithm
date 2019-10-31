//LeetCode:83
//2019-10-31
#include<iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* ln = head;
        while(ln->next){
            if(ln->val == ln->next->val){
                ln->next = ln->next->next;
            } else{
                ln = ln->next;
            }    
        }
        return head;  
    }   
};