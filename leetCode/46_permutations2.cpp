#include<vector>
class Solution {
//2019-10-31
//用pos来标记第i个数是否已经使用过。
//先列出nums[0]在首位的所有排列，再列出nums[1]在首位的所有排列。
public:
    std::vector<std::vector<int> > permute(std::vector<int>& nums) {
        std::vector<std::vector<int> > result;
        std::vector<bool> pos(nums.size(), false);
        std::vector<int> tmp;
        backtrack(nums, pos, result, tmp);
        return result;
    }

    void backtrack(const std::vector<int> &nums,
                   std::vector<bool> &pos,
                   std::vector<std::vector<int> > &result,
                   std::vector<int>& tmp)
    {
        if(tmp.size() ==  nums.size()){
            result.push_back(tmp);
            return;
        }

       for(int i = 0; i < nums.size(); i++){
            if(pos[i]) {
                continue;
            }
            pos[i] = true;
            tmp.push_back(nums[i]);
            backtrack(nums, pos, result, tmp);
            pos[i] = false;
            tmp.pop_back();
        }
    }
};