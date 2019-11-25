#include<vector>
#include<stack>
class Solution {
//一列一列的计算，找出每一列左边的最大值和右边的最小值
//如果最小值比当前大，则加上min - height[i]
public:
    int trap(std::vector<int>& height)
    {
        if(height.size() == 0){
            return 0;
        }
        int sum = 0;
        std::stack<int> s;
        for(int i = 0; i < height.size(); i++){
            while(!s.empty() && height[i] > height[s.top()]){
                int top = s.top();
                s.pop();
                if(s.empty()){
                    break;
                }
                int width = i - s.top() - 1;
                int depth = std::min(height[i], height[s.top()]) - height[top];
                sum += width *  depth;
            }
            s.push(i);
        }
        return sum;  
    }
    
    int trapII(std::vector<int>& height){
        //一列一列的计算，找出每一列左边的最大值和右边的最小值
         //如果最小值比当前大，则加上min - height[i]
        if(height.size() == 0){
            return 0;
        }
        int sum = 0;
        for(int i = 1; i < height.size() -1; i++)
        {
            int leftMax = 0;
            for(int j = 0; j < i; j++){
                if(leftMax < height[j]){
                    leftMax = height[j];
                }
            }
            int rightMax = 0;
            for(int j = i+1; j < height.size(); j++){
                if(rightMax < height[j]){
                    rightMax = height[j];
                }
            }
            int min = std::min(leftMax, rightMax);
            if(height[i] < min){
                sum += min - height[i];
            }
        }
        return sum;
    }
};