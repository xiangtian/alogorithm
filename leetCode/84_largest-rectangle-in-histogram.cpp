#include<vector>
#include<stack>
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        //遍历数组一遍、出栈一遍、所以时间复杂度为O(2n)
        int maxArea = 0;
        std::stack<int> s;
        s.push(-1);
        for(int i = 0; i < heights.size(); i++){
            while(s.top() != -1 && heights[i] <= heights[s.top()]){
                int top = s.top();
                s.pop();
                int area = heights[top] * (i - s.top() -1);
                maxArea  = std::max(area, maxArea);
            }
            s.push(i);   
        }
        while(s.top() != -1){
            int top = s.top();
            s.pop();
            int width = heights.size() -1 - s.top();//上一位置和最后一列所围成的最小值
            maxArea = std::max(maxArea, heights[top] * width);
        }
        return maxArea; 
    }

    int largestRectangleAreaII(std::vector<int>& heights) {
        //每次计算当前i之前的所有能组成的矩形的面积，取出最大值O(n^2)，竟然没有超时
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++){
            int area = heights[i];
            int minHeight = heights[i];
            for(int j = i; j >=0; j--){
                if(heights[j] < minHeight){
                    minHeight = heights[j];
                }
                int tmp = minHeight * (i -j + 1);
                if(area < tmp){
                    area = tmp;
                }
            }
            if (maxArea <= area){
                maxArea = area;
            }
        }
        return maxArea; 
    }
};