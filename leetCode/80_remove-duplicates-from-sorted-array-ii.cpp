#include<vector>
class Solution {
//从左向右遍历、如果下一个元素等于当前元素&&hasDup==false,
//左指针和i同时后移,否则只移动i。
public:
    int removeDuplicates(std::vector<int>& nums) {
        if(nums.size() <= 2){
            return nums.size();
        }
        bool hasDup = false;
        int left = 0;
        int right = 0;
        while(right < nums.size())
        {
            if((right+1) < nums.size()){
                if(nums[right+1] == nums[right]){
                    if(!hasDup){
                        nums[left++] = nums[right++];
                        hasDup = true;
                    } else {
                        right++;
                    }
                } else {
                    nums[left++] = nums[right++];
                    hasDup = false;
                }
            }else {
                nums[left++] = nums[right++];
            }
        }
        return left-1; 
    }
};