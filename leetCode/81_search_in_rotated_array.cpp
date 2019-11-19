#include<vector>
#include<iostream>
class Solution {
//2019-11-15
//先利用153题的方法，找到含有重复元素的最小值
//然后找到最小值的左边界之后，对target进行二分查找
public:
    bool search(std::vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int minIdx = findMin(nums);
        if(nums[minIdx] == target){
            return true;
        }

        int left = minIdx;//寻找左边界
        std::cout << minIdx << std::endl;
        while(left >=0 && nums[left] == nums[minIdx]){
            left--;
        }
        if(left == -1){//左边界在起始位置
            int right = nums.size() - 1;
            //[1, 3, 1, 1, 1]
            while(minIdx == 0 && nums[right] == nums[minIdx] && right > 1) right--;
            return binarySearch(nums, minIdx, right, target);
        } else{
            if(target >= nums[0]){//找到了左边界
                return binarySearch(nums, 0, left, target);
            } else {
                return binarySearch(nums, minIdx, nums.size() -1, target);
            }
        }
    }

    bool binarySearch(std::vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int mid = (left + right) / 2;
            if(target < nums[mid]){
                right = mid -1;
            } else if (target > nums[mid]){
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }

    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() -1;
        while(left < right && nums[left] == nums[right]){
            right--;
        }
        int mid = left;
        while(left < right){//退出条件是left=right
            mid = (left + right) / 2;
            if(nums[mid] <= nums[right]){//nums[mid] <=nums[right] 最小值在左侧
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return  right;
    }
};