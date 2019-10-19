//LeetCode: 152
//2019-10-18
#include<vector>
#include<iostream>
class Solution {
//以当前节点结束的最大最小值、一定从当前节点、以及当前节点和上次节点最大最小值的乘积中选取
//2019-10-18
public:
    int maxProduct(std::vector<int>& nums) {
         if(nums.size() == 1){
            return nums[0];
        }
        
        int currentMax = 1;
        int currentMin = 1;
        int maxProduct = INT_MIN;
        for(int i = 0;i < nums.size(); i++){
            int aa = currentMax * nums[i];
            int bb = currentMin * nums[i];
            //以当前节点结束的最大最小值、一定从当前节点、以及当前节点和上次节点最大最小值的乘积中选取
            currentMax = std::max(nums[i], std::max(aa, bb));//
            currentMin = std::min(nums[i], std::min(aa, bb));
            if(maxProduct < currentMax){
                maxProduct = currentMax;
            }
        }
        return maxProduct;    
    }
};