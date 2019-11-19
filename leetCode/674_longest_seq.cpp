#include<vector>
class Solution {
//2019-11-15
//记录递增的次数
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        if (nums.size() <= 1){
            return nums.size();
        }
        int count = 1;
        int maxCount = 1;
        for(int i = 0; i < nums.size(); i++){
            if((i + 1) < nums.size() && nums[i] < nums[i+1]){
                count++;
                maxCount = std::max(maxCount, count);
            } else{
                if(i != nums.size() -1){
                  count = 1;
                } 
            }
        }
        return maxCount;
        
    }
};