#include<iostream>
#include<vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
       if(node->next){
           node->val = node->next->val;
           node->next = node->next->next;
       } else{
           node = NULL;
       }   
    }
};