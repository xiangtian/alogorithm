#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
//2019-11-20
//如果左子树和右子树相等，则比较left->left和right->right, left->right和right->left
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isEqual(root->left, root->right);
    }

    bool isEqual(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL){
            return true;
        } else if (left == NULL || right == NULL){
            return false;
        } else {
            if(left->val == right->val){
                return isEqual(left->left, right->right) && isEqual(left->right, right->left);
            }
            return false;
        }
    }
};