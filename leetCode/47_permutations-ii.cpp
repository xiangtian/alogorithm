//LeetCode: 47
//2019-10-31
#include<vector>
class Solution {
//2019-10-31
//最重要的两步，排序，然后再减枝。
public:
    std::vector<std::vector<int> > permuteUnique(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
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
            if (i > 0 && nums[i] == nums[i - 1] && !pos[i - 1]){
                    continue;//减枝，如果和当前元素的前一个元素还没放，则不放当前元素
            }
            pos[i] = true;
            tmp.push_back(nums[i]);
            backtrack(nums, pos, result, tmp);
            pos[i] = false;
            tmp.pop_back();
        }
    }
};