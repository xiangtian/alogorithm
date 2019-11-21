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
//postIdx总是当前树或者子树的根，先找到中序数组中找到root的位置。
//使用中序数组的左半部分构建左子树，右半部分构建右子树
//左子树的根为后序数组中的postIdx - 右子树元素 的前一个。 右子树的根为后序数组postIdx - 1
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
       TreeNode* root =  build(postorder, postorder.size() -1, inorder, 
                               0, postorder.size() -1);
        return root;
    }

    TreeNode* build(std::vector<int>& postorder, int postIdx, 
                    std::vector<int>& inorder, int start, int end){
        if(start > end){
            return NULL;
        }
        int rootVal = postorder[postIdx];
        //找到root所在的位置
        int rootIdx = std::find(inorder.begin() + start, inorder.begin()+ end, rootVal) - inorder.begin();
        TreeNode* root = new TreeNode(rootVal);
        //从postorder中确定leftRoot的起始位置
        int leftRoot = postIdx - (end - rootIdx + 1);
        root->left = build(postorder, leftRoot, inorder, start, rootIdx -1);
        //从postorder中确定rightRoot的起始位置
        int rightRoot = postIdx - 1;
        root->right = build(postorder, rightRoot, inorder, rootIdx + 1, end);
        return root;
    }
};