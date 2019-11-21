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
//非递归实现，将当前节点入栈，然后指针指向其左子树，直到最左下角的元素
//获取栈顶元素，看起是否有右子树，并且右子树不等于最后被访问的节点，则将右子树入栈
//否则出栈，访问当前节点，同时将指针设置为空，有利于下一次弹栈。
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* p = root;
        TreeNode* lastNode = NULL;//记录最后一个push到result中的节点
        
        while(p || !s.empty()){
            if(p){
                s.push(p);
                p = p->left;
            } else{
               if(!s.empty()){
                   p = s.top();
                   if(p->right && p->right != lastNode){
                   //如果当前节点的右子树不是最后一个访问的节点、遍历右子树。
                       p = p->right;
                   } else{
                       lastNode = p;//记录最后一个访问的节点
                       result.push_back(p->val);
                       s.pop();
                       p = NULL;
                   }     
               }
            }
        } 

        return result;
    }
      
    std::vector<int> postorderTraversalII(TreeNode* root) {
        std::vector<int> result;
        travel(root, result);
        return result;   
    }

    void travel(TreeNode* root, std::vector<int>& result){
        if(root == NULL){
            return;
        }

        travel(root->left, result);
        travel(root->right, result);
        result.push_back(root->val); 
    }
};