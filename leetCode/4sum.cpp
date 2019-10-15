//LeetCode: 18
//2019-10-14
#include<vector>
class Solution {
//相对于ThreeSum多了一层循环，解法仍然使用双指针
public:
    std::vector<std::vector<int> > fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int> > result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++)
            {
                if(j > i+ 1 && nums[j] == nums[j-1]) {
                    continue;
                }
                int left = j + 1, right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[left] + nums[right] + nums[i] + nums[j] > target)
                    {
                        right--;
                    }
                    else if (nums[left] + nums[right] + nums[i] + nums[j] < target)
                    {
                        left++;
                    }
                    else
                    {
                        std::vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[left]);
                        v.push_back(nums[right]);
                        result.push_back(v);
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1])
                            ++left;
                        while (left < right && nums[right] == nums[right + 1])
                            --right;
                    }
                }
            } 
        }
        return result;
        
    }
};