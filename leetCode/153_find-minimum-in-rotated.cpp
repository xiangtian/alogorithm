//LeetCode: 153
//2019-10-29
#include<vector>
class Solution {
//2019-10-29
//根据旋转的特点，初始时最右端的一定小于最左端的。
public:
    int findMin(std::vector<int>& nums) {
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
        return  nums[right];
        
    }
};