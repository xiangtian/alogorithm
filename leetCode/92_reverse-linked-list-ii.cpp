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
    ListNode* reverseList(ListNode* head, int m, int n) {
      class Solution {
//2019-11-11
//找到m的前一个元素，然后依次reverse n-m次，本题没有做参数校验
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL){
            return head;
        }
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* node = head;
        ListNode* preNode = preHead;
        int k = 1;
        int r = n - m;
        while(k++ < m){
            preNode = node;
            node = node->next;
        }
        while(r-- > 0){
            ListNode* tmp = preNode->next;
            preNode->next = node->next;
            node->next = node->next->next;
            preNode->next->next = tmp;
        }
        ListNode* ret = preHead->next;
        delete preHead;
        return ret;  
    }
};