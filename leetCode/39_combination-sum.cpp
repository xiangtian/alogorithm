//LeetCode: 39
//2019-10-31
#include<vector>
class Solution {
//回溯的经典思想、递归的减当前位置的元素，直到target<=0。
//因为允许重复使用，所以每次都从当前位置的元素向下递归。
public:
    std::vector<std::vector<int> > combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int> > result;
        std::vector<int> tmp;
        backtrack(0, candidates, tmp, result, target);
        return result;
    }

    void backtrack(int idx, 
                   const std::vector<int>& candidates, 
                   std::vector<int>& tmp, 
                   std::vector<std::vector<int> >& result, 
                   int target){
        if(target < 0){
            return;
        }

        if(target == 0){
            result.push_back(tmp);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            tmp.push_back(candidates[i]);
            backtrack(i, candidates, tmp, result, target - candidates[i]);//递归的求解
            tmp.pop_back();
        }
    }

};