//LeetCode: 61
//2019-10-31
#include<iostream>
#include<vector>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
//2019-10-31
//先计算链表长度，然后使用双指针移动
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){//判断链表是否为空
            return head;
        }
        ListNode* lp = head;
        int length = 0;
        while(lp){
            length++;
            lp = lp->next;
        }
        k = k % length;
        if(k == 0){
            return  head;
        }

        ListNode *preHead = new ListNode(0);
        preHead->next = head;
        ListNode* left = preHead;
        lp = head;
        while(--k){//右指针向前移动k-1步
            lp = lp->next;
        }
        while(lp->next){//移动到最后一个元素
            lp= lp->next;
            left= left->next;
        }

        preHead->next = left->next;
        lp->next = head;
        left->next = NULL;

        ListNode* ret = preHead->next;
        delete preHead;
        return ret;   
    }
};