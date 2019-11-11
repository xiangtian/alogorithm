#include<iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
//2019-11-11
//reverse LinkList
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* node = head;
        while(node->next){
            ListNode* tmp = preHead->next;
            preHead->next = node->next;
            node->next = node->next->next;
            preHead->next->next = tmp;
        }
        ListNode* ret = preHead->next;
        delete preHead;
        return ret;  
    }
};