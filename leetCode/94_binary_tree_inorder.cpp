#include<iostream>
#include<vector>
#include<stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
//2019-11-20
//中序遍历左子树、然后遍历根、最后遍历右子树
public:
    std::vector<int> inorderTraversal(TreeNode* root){
        std::vector<int> result;
        TreeNode* p = root;
        std::stack<TreeNode*> s;
        while(p || !s.empty()){
            if(p){
                s.push(p);
                p = p->left;
            } else if(!s.empty()){
                TreeNode* q = s.top();
                result.push_back(q->val);
                s.pop();
                p = q->right;
            } 
        }
        return result;

    }
    std::vector<int> inorderTraversalIII(TreeNode* root) {
        std::vector<int> result;
        travel(root, result);
        return result;
    }

    void travel(TreeNode* root, std::vector<int>& result){
        if(root == NULL){
            return;
        }
        travel(root->left, result);
        result.push_back(root->val);
        travel(root->right, result);
    }

    std::vector<int> inorderTraversalII(TreeNode* root) {
        std::vector<int> result;
        if(root == NULL){
            return result;
        }
        std::vector<int> left = inorderTraversal(root->left);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);
        std::vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }
};