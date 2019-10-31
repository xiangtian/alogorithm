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
//2019-10-31
//使用标志位hasDup来判断是否移除当前元素。
//使用preNode指向要移除元素的前一个
public:
     ListNode* deleteDuplicates(ListNode* head) {
        if(!head) {
            return head;
        }
        ListNode* preHead = new ListNode(0);
        preHead->next = head;
        ListNode* ln = head;
        ListNode* preLn = preHead;
        bool hasDup = false;
        while(ln){
            if(ln->next && ln->val == ln->next->val){
                hasDup = true;
                ln->next = ln->next->next;
            } else{
                if(hasDup){
                    preLn->next = preLn->next->next;
                } else{
                    preLn = preLn->next;
                }
                ln = ln->next;
                hasDup = false;
            }    
        }
        ListNode* ret = preHead->next;
        delete preHead;
        return ret;  
    }   
};