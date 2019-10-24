//LeetCode: 27
//2019-10-24
#include<vector>
class Solution {
//i始终指向下一个要插入元素的位置
public:
    int removeElement(std::vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};