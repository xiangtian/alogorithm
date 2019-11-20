
#include<vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
//2019-11-20
//递归的将数组的中点设置为root
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
      return toBST(nums, 0, nums.size() -1);  
    }

    TreeNode* toBST(std::vector<int>& nums, int low, int high){
        if(low > high){
            return NULL;
        }
        int mid = (low + high) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = toBST(nums, low, mid-1);
        root->right = toBST(nums, mid+1, high);
        return root;
    }
    
};