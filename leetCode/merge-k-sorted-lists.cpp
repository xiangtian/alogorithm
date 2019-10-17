//LeetCode: 23
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
//基本上次采取归并排序的思想、每次取两个链表进行merge、直到q中只剩一个链表
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }
        std::queue<ListNode*> q;
        for(int i = 0; i < lists.size();){
            if((i+1) < lists.size()){
                q.push(mergeTwoLists(lists[i], lists[i+1]));
            } else {
                q.push(lists[i]);
            }
            i = i+2;
        }

        while(q.size() > 1){
            ListNode* first = q.front();
            q.pop();
            ListNode* second = q.front();
            q.pop();
            q.push(mergeTwoLists(first, second));
        } 
        return q.front();   
    }
private: 
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        ListNode* ret = new ListNode(0);
        ListNode* current = ret;
        while(h1 && h2){
            if (h1->val < h2->val){
                current->next = h1;
                current = current->next;
                h1 = h1->next;
            } else {
                current->next = h2;
                current = current->next;
                h2 = h2->next;
            }
        }     
        if(h1) {
            current->next = h1;
            current = current->next;
            h1 = h1->next;    
        }
        if(h2){
            current->next = h2;
            current = current->next;
            h2 = h2->next;
        }
        ListNode* r = ret->next;
        delete ret;
        return r;
    }
};