#include<iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
//2019-11-12
//相遇后、另外一个指针从头开始遍历，直到再次相遇，相遇的地点即为环的入口。
//Floyd算法
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(fast){
                fast = fast-> next;
            }
            if(fast == NULL){
                return NULL;
            }
            if(fast == slow){//相遇
                break;
            }
        }
        //相遇后、另外一个指针从头开始遍历，直到再次相遇，相遇的地点即为环的入口。
        //Floyd算法
        ListNode* p = head;
        while(p != slow){
            p = p->next;
            slow = slow->next;
        }  
        return p;
    }
};