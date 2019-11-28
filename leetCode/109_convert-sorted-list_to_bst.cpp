#include<iostream>
struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
//2019-11-27
//使用快慢指针，找到链表的重点，然后断开链表，递归的执行下去
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }

        if(head->next == NULL){
            return new TreeNode(head->val);
        }
        ListNode* pre = head;
        ListNode* slow = head->next;
        ListNode* fast = head->next->next;
        while(fast && fast->next){
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;//断开链表
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};