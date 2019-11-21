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
//依次把当前节点的右子树放入到栈中，直到最左边的左子树
//然后依次将右子树出栈
public:
     std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
            if(p){
                result.push_back(p->val);
                if(p->right){
                    s.push(p->right);
                }
                p = p->left;
            } else{
               if(!s.empty()){
                   p = s.top();
                   s.pop();
               }
            }
        } 
        return result;
    }
      
    std::vector<int> preorderTraversalI(TreeNode* root) {
        std::vector<int> result;
        travel(root, result);
        return result;   
    }

    void travel(TreeNode* root, std::vector<int>& result){
        if(root == NULL){
            return;
        }

        result.push_back(root->val);
        travel(root->left, result);
        travel(root->right, result);
    }
};