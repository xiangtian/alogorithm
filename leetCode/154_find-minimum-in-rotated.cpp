//LeetCode: 154
//2019-10-30
#include<vector>
class Solution {
//和153题基本上相同，唯一的不同就是开始时将right移动到与left不等的位置
public:
    int findMin(std::vector<int>& nums) {
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
        return  nums[right];
    }
};