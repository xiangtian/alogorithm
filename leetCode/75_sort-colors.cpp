#include<vector>
class Solution {
//2019-11-14
//从左向右遍历nums，如果发现nums=0，则和最左边的元素交换、否则和最后边的元素交换
public:
    void sortColors(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        for(int i = left; i < nums.size() && left <= right; i++){
            if(nums[i] == 1){
                continue;
            }
            while((nums[i] == 0 || nums[i] == 2) && i >= left && i <= right){
                if(nums[i] == 0){
                    int tmp = nums[left];
                    nums[left] = nums[i];
                    nums[i] = tmp;
                    left++;
                } else{
                    int tmp = nums[right];
                    nums[right] = nums[i];
                    nums[i] = tmp;
                    right--;
                }
            }
        }
    }
};