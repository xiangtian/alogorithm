#include<vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
//2019-11-19
//同96题的思路基本一致
public:
    std::vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode*> result;
        if(n == 0){
            return result;
        }
        return genTrees(1, n);
    }

    std::vector<TreeNode*> genTrees(int start, int end){
        std::vector<TreeNode*> allTrees;
        if(start > end){
            allTrees.push_back(NULL);
            return allTrees;
        }
        for(int idx= start; idx <= end; idx++){
            std::vector<TreeNode*> leftTrees = genTrees(start, idx-1);//递归的生成前i-1棵树
            std::vector<TreeNode*> rightTrees = genTrees(idx+1, end);//递归的生成i之后续的数
            for(int i = 0; i < leftTrees.size(); i++){
                for(int j = 0; j < rightTrees.size(); j++){
                    TreeNode *root = new TreeNode(idx);
                    root->left = leftTrees[i];
                    root->right = rightTrees[j];
                    allTrees.push_back(root);
                }
            }
        }
        return allTrees;
    }
};