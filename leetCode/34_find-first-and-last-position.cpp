#include<vector>
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result;
        int left = 0, right = nums.size() -1;
        if(nums.size() == 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
 
        int first = findPos(nums, left, right, target - 0.5);
        int last = findPos(nums, left, right, target + 0.5);
        if(first == last){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        } else {
            result.push_back(first);
            result.push_back(last-1);
            return result;
        }
    }

    int findPos(const std::vector<int>& nums, int left, int right, double target){
        int mid = left;
        while(left <= right){
            mid = (left + right) / 2;
            if(target < nums[mid]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left; 
    }
};