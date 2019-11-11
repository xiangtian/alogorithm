//LeetCode: 86
//2019-11-10
#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
//2019-11-10
//先找到第一个大于等于x的之前的位置preNode
//然后使用另外一个指针向后查找、将小于x的节点插入到preNode之后，
//然后将preNode后移一位
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* preNode = preHead;
        //找到大于等于x的第一个节点
        while(preNode->next && preNode->next->val < x){
            preNode = preNode->next;
        }
        ListNode * right = preNode;
        while(right && right->next){
            if(right->next->val < x){
               ListNode* tmp = preNode->next;
               preNode->next = right->next;
               right->next = right->next->next;
               preNode = preNode->next;
               preNode->next = tmp;
            } else{
                right = right->next;
            }
        }
        ListNode* ret = preHead->next;
        delete preHead;
        return ret;   
    }
};