//LeetCode:198
//2019-10-18
#include<vector>
class Solution {
public:
//动态规划方程：dp[n] = MAX( dp[n-1], dp[n-2] + num )
//由于不可以在相邻的房屋闯入，所以在当前位置 n 房屋可盗窃的最大值，
//要么就是 n-1 房屋可盗窃的最大值，要么就是 n-2 房屋可盗窃的最大值加上当前房屋的值，二者之间取最大值
    int rob(std::vector<int>& nums){
        int preMax = 0;//nums[i-2]结尾的最大值
        int currentMax = 0;//nums[i-1]结尾的最大值
        for(int i = 0; i < nums.size(); i++){
            int tmp = currentMax;
            currentMax = std::max(preMax + nums[i], currentMax);
            preMax = tmp;
        }
        return currentMax;
    }

private:
//以当前节点结束的最大值、取决于该节点前的第二个和第三个的最大值加上当前节点
//maxOf(n) = max(maxOf[n-2], maxOf[n-3]) + nums[n]
    int rob1(std::vector<int>& nums) {
        std::vector<int> v(nums.size(), 0);
        for(int i= 0; i < nums.size(); i++){
            if(i < 2){
                v[i] = nums[i];
            } else if(i==2){
                v[i] = v[i-2] + nums[i];
            } else{
                v[i] = std::max(v[i-2], v[i-3]) + nums[i];
            }
        }
        return v[nums.size() - 1]; 
    }
};