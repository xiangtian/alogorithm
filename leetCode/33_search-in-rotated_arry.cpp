//LeetCode: 33
//2019-10-29
#include<vector>
class Solution {
//2019-10-29
//对比153题，先找出最小值的idx，然后分别查找是否存在、注意边界条件
public:
    int search(std::vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        if(nums.size() == 1){
            return nums[0] == target ? 0 : -1;
        }
        int left = 0, right= nums.size() -1;
        int minIdx = findMin(nums);
        int result = find(nums, left, minIdx, target);
        if (result == -1){
            result = find(nums, minIdx, right, target);
        }
        return result;
    }

    int find(const std::vector<int>& nums, int left, int right, int target){
        int mid = left;
        while(left <= right){
            mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            } else if(nums[mid] > target){
                right = mid -1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    int findMin(const std::vector<int>& nums){
         int left = 0, right = nums.size() -1;
        if(nums[left] <= nums[right]){
            return nums[left];
        }
        int mid = left;
        while(left < right){//退出条件是left=right
            mid = (left + right) / 2;
            if(nums[mid] <= nums[right]){//nums[mid] <=nums[right] 最小值在左侧
                right = mid;
            } else{
                left = mid + 1;//否则在右侧
            }
        }
        return right;
    }
        
};