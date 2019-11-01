//LeetCode: 40
//2019-10-31
#include<vector>
class Solution {
//排序后，进行回溯。当遇到相同的元素时，result中元素不在candidates排序好的位置中时，跳过
public:
    std::vector<std::vector<int> > combinationSum2(std::vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
            if(i != idx && candidates[i] == candidates[i-1]) continue;//去重
            tmp.push_back(candidates[i]);
            backtrack(i + 1, candidates, tmp, result, target - candidates[i]);
            tmp.pop_back();
        }
    }
};