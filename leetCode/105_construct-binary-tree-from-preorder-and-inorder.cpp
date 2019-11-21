#include<vector>
#include<algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
//2019-11-21
//start总是当前树或者子树的根，先找到中序数组中找到root的位置。
//使用中序数组的左半部分构建左子树，右半部分构建右子树
//左子树的根为前序数组中的preIdx下一个。 右子树的根为前序数组preIdx + 左子树元素的个数
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
   TreeNode* root =  build(preorder, 0, inorder, 0, preorder.size() -1);
         return root;
    }

    TreeNode* build(std::vector<int>& preorder, int preIdx, 
                    std::vector<int>& inorder, int start, int end){
        if(start > end){
            return NULL;
        }
        int rootVal = preorder[preIdx];
        //找到root所在的位置
        int rootIdx = std::find(inorder.begin() + start, inorder.begin()+ end, rootVal) - inorder.begin();
        TreeNode* root = new TreeNode(rootVal);
        root->left = build(preorder, preIdx+1, inorder, start, rootIdx -1);
        //从preoder中确定rightRoot的起始位置
        int rightRoot = preIdx + rootIdx - start + 1;
        root->right = build(preorder, rightRoot, inorder, rootIdx + 1, end);
        return root;
    }
};