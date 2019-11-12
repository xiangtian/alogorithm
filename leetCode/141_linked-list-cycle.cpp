#include<iostream>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(fast){
                fast = fast-> next;
            }
            if(fast == NULL){
                return false;
            }
            if(fast == slow){
                return true;
            }
        }
        return false;  
    }
};