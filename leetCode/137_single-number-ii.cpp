#include<vector>
class Solution {
//2019-11-13
//出现3次的位上对应的1的count数为3的倍数,算法复杂度为O(32n)
public:
    int singleNumber(std::vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < 32; i++){
            int count = 0;
            int mask = 1 << i;
            for(int j = 0; j < nums.size(); j++){
                if((nums[j]& mask) != 0){
                    count++;
                }
            }
            if(count % 3 != 0){
                result |= mask;
            }
        }
        return result;  
    }