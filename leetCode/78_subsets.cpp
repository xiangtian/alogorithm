#include<vector>
class Solution {
//利用77题求出组合中元素个数等于k的组合。令k=1，2...nums.size()
public:
    std::vector<std::vector<int> > subsets(std::vector<int>& nums) {
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
            tmp.push_back(nums[i]);
            backtrack(i+1, k, nums, tmp, result);
            tmp.pop_back();
        }
    }
};