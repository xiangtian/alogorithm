//LeetCode: 53
//2019-10-17
#include<vector>
class Solution {
// 动态规划最简单的例子
// 状态转移方程：sum[i] = max{sum[i-1]+a[i],a[i]}   
// 其中(sum[i]记录以a[i]为子序列末端的最大序子列连续和)
// 2019-10-17
public:
    int maxSubArray(std::vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        //在每一个扫描点计算以该点数值为结束点的子数列的最大和
        int endMax = nums[0];//以当前节点终点的最大值
        int max = nums[0];//当前的最大值

        for(int i = 1; i < nums.size(); i++){
            // 以每个位置为终点的最大子数列 都是基于其前一位置的最大子数列计算得出,
            endMax = std::max(endMax + nums[i], nums[i]);
            max = std::max(endMax, max);
        }
        return max;
    }
};