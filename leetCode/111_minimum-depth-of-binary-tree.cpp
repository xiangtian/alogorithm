#include<iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
//2019-11-20
//需要注意的是到叶子节点的最小深度
public:
    int minDepth(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);

        if(root->left == NULL){
            return right + 1;
        } 
        if(root->right == NULL){
            return left + 1;
        }
        return std::min(left, right) + 1;
    }
};