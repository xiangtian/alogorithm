//LeetCode: 46
//2019-12-28
#include<vector>
class Solution {
//2019-10-28
//使用回溯的方法、首先把第一个元素放在第一个位置、然后看第二个元素可以放在哪些位置
//使用一个数组来标记当前位置是否已经放入元素，没有则可以放入
public:
    std::vector<std::vector<int> > permute(std::vector<int>& nums) {
        std::vector<std::vector<int> > result;
        std::vector<int> pos(nums.size(), -1);
        backtrack(0, nums.size(), nums, pos, result);
        return result;
    }

    void backtrack(int idx, int size, const std::vector<int>& nums, 
        std::vector<int>& pos, std::vector<std::vector<int> > & result){
        if(idx > size -1){
            std::vector<int> r;
            for(int i = 0; i < size; i++){
                r.push_back(nums[pos[i]]);
            }
            result.push_back(r);
            return;
        }
        for(int i = 0; i < size; i++){
            if(pos[i] == -1){
                pos[i] = idx;
                backtrack(idx + 1, size, nums, pos, result);
                pos[i] = -1;
            }
        }
    }
};