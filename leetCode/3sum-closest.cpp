//LeetCode: 16
//2019-10-15
#include<vector>
#include<map>
#include<set>
#include<iostream>
class Solution {
//和三数之和的解法基本上一样、采用双向指针进行遍历、同时使用min来保持最小值
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        int result = 0;
        int min = INT_MAX;
        sort(nums.begin(), nums.end());//排序
        for(int i = 0; i< nums.size(); i++){//时间复杂度n^2
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size() -1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum > target){
                    if (sum - target <= min){
                        min = sum - target; // 切换最小值
                        result = sum;
                    }
                    right--;
                    while(left < right && nums[right] == nums[right+1]) --right; //去重
                } else {
                    if (target - sum <= min){
                        min = target - sum; //切换最小值
                        result = sum;
                    }
                    left++;
                    while(left< right && nums[left]== nums[left-1]) ++left;//去重
                }
            }
        }
        return  result;
        
    }
};