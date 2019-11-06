#include<vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxDist = nums[0];
        for (int i = 1; i < nums.size() && i <= maxDist; i++){
            if (i + nums[i] > maxDist){
                maxDist = i + nums[i];
                if (maxDist >= nums.size() - 1){
                    return true;
                }
            }
        }
        return false;
    }

    bool canJumpII(std::vector<int>& nums){
        if(nums.size() == 0){
            return true;
        }
        int maxDist = nums[0];
        for (int i = 0; i < nums.size() && i <= maxDist; i++){
            if (i + nums[i] >= maxDist){
                maxDist = i + nums[i];
                if (maxDist >= nums.size() - 1){
                    return true;
                }
            }
        }
        return false;
    }
};