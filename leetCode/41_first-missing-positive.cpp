#include<vector>
class Solution {
//1.特判，若nums为空，则返回1
//2.遍历数组，进入循环，循环条件：对于索引i处的nums[i]，
//nums[i]-1是否满足在索引范围[0,n-1],且nums[i]!=nums[nums[i]-1]，表示若索引处已经存放一个正确元素，则退出循环。
//3.交换nums[nums[i]-1]和nums[i]
//4.遍历数组，找到第一个nums[i]!=i+1，返回i+1，若遍历结束不返回，则返回n+1。
public:
    int firstMissingPositive(std::vector<int>& nums) {
        if(nums.size() == 0){
            return 1;
        }

        for(int i = 0; i < nums.size(); i++){
            //!!!!只要当前nums[i]的值在有效范围内，就将nums[i]放入正确的位置。
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]){
                int tmp = nums[i];
                nums[i] = nums[tmp -1];
                nums[tmp-1] = tmp;
            }
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i + 1){
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};