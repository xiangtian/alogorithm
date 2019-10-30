//LeetCode: 31
//2019-10-24
#include<vector>
class Solution {
//每次从当前元素的后面查找比当前元素大的最小值，然后交换,然后将剩余元素排序
//如果没有交换过，则reverse数组
public:
    void nextPermutation(std::vector<int>& nums) {
        for(int i = nums.size() -2; i >=0; i--){//从倒数第二个元素开始查找
            bool hasBig = false;
            int  idx = nums.size();
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] > nums[i]){
                   if(!hasBig){
                       idx = j;
                       hasBig = true;
                   } else{
                       if (nums[j] < nums[idx]){
                           idx = j;
                       }
                   }  
                }
            }
            if (hasBig){
                int tmp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = tmp;
                if(nums.begin() + i + 1 < nums.end()) {
                    sort(nums.begin() + i+1, nums.end());
                }
                return;
            }
        }
        std::reverse(nums.begin(),nums.end());  
    }
};