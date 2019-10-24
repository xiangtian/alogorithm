#include <iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
         if(k == 1){
            return head;
        }

        ListNode* blankHead = new ListNode(0);
        blankHead->next = head;
        ListNode* preLeft = blankHead;
        ListNode* left = head;
        ListNode* right = head;
        int i = 1;
        while(right){
            if(i % k == 0){
                ListNode* afterRight = right->next;
                while(left->next != afterRight){//停止的条件
                    ListNode* tmp = preLeft->next;
                    preLeft->next = left->next;
                    left->next = left->next->next;
                    preLeft->next->next = tmp;
                }
                preLeft = left;
                left = preLeft->next;
                right = left;
                i = 1;//重置i
            } else {
                i++;
                right = right->next;
            }
        }
        ListNode* ret = blankHead->next;
        delete blankHead;
        return ret;
    }
};