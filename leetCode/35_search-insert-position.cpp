#include<vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0, right = nums.size() -1;
        if(nums.size() == 0){
            return -1;
        }

        int mid = left;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] < target){
                right = mid -1;
            } else if (nums[mid] > target){
                left = mid + 1;
            } else {
                return mid;
            }
        } 
        return left;  
    }
};