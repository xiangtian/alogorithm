//LeetCode: 11
//2019-10-17
#include<vector>
class Solution {
//较小的高度移动、才可能取比较大的值
public:
    int maxArea(std::vector<int>& height) {
        int max = 0;
        int i = 0, j = height.size() -1;
        while(i < j){
            max = std::max(std::min(height[i], height[j]) * (j - i), max);
            if(height[i] < height[j]){
                i++;
            } else {
                j--;
            }
        }
        return max;
    }
};