#include<vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int step = 0;
        int lastIdx= 0;
        int fastIdx = nums[0];
        while(true){
            step++;
            if(fastIdx >= nums.size() -1){
                return step;
            }
            int local = fastIdx;
            for(int i = lastIdx + 1; i <= fastIdx; i++){
                if(i + nums[i] >= local){
                    local = i + nums[i];
                }
            }
            lastIdx = fastIdx;
            fastIdx = local;
        }
        return 0;
    }
};