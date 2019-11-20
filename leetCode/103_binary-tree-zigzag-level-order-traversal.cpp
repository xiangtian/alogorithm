#include<iostream>
#include<vector>
#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
//2019-11-20
//依次将指针放入Queue中，然后遍历Queue，广度优先遍历
//根据tierCount来判断是否要reverse
public:
    std::vector<std::vector<int> > levelOrder(TreeNode* root) {
        std::vector<std::vector<int> > result;
        if(root == NULL){
            return result;
        }
        std::queue<TreeNode*> q;
        q.push(root);
        int tierCount = 0;
        while(!q.empty()){
            int size = q.size();
            std::vector<int> tier;
            while(size--){
                TreeNode* p = q.front();
                tier.push_back(p->val);
                q.pop();
                if(p->left) {
                    q.push(p->left);
                } 
                if(p->right){
                    q.push(p->right);
                }
                
            }
            if(tierCount % 2 != 0){
                std::reverse(tier.begin(), tier.end());
            }
            result.push_back(tier);
            tierCount++;
        }  
        return result;   
    }
};