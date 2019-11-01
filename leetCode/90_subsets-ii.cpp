#include<vector>
class Solution {
public:
    std::vector<std::vector<int> > subsetsWithDup(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > result;
        std::vector<int> tmp;
        result.push_back(tmp);
        for(int k = 1; k <= nums.size(); k++){
            backtrack(0, k, nums, tmp, result);
        }
        return result;
    }

    void backtrack(int idx,int k, 
                   std::vector<int>& nums,
                   std::vector<int>& tmp, 
                   std::vector<std::vector<int> >& result){
        if(tmp.size() == k){
            result.push_back(tmp);
            return;
        }
        
        for(int i = idx; i< nums.size(); i++){
            if(i > 0 && i !=idx && nums[i]==nums[i-1]){//去重
                continue;
            }
            tmp.push_back(nums[i]);
            backtrack(i+1, k, nums, tmp, result);
            tmp.pop_back();
        }
    }    
};