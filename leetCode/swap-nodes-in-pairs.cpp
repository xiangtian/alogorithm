//LeetCode: 24
//2019-10-17
#include<iostream>
#include<vector>
#include<queue>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
//主要是设置头结点，取得两个节点的pre，然后解链，重新构建链表
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* pre = preHead;
        ListNode* current = head;
        while(current && current->next){
            pre->next = current->next;
            current->next = current->next->next;
            pre->next->next = current;
            pre = current;
            current = current->next;
        } 
        ListNode* ret = preHead->next;
        delete preHead;
        return ret;
        
    }
};