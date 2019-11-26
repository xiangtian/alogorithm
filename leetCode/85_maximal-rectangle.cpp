#include<vector>
#include<stack>
class Solution {
//2019-11-25
public:
    int maximalRectangle(std::vector<std::vector<char> >& matrix) {
        //根据84题的结论来计算、计算每一行的矩形的高度来计算最大面积。
        if(matrix.size() == 0){
            return 0;
        }
        int area = 0;
        std::vector<int> heights(matrix[0].size(), 0);
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size();j++){
                if(matrix[i][j] == '0'){
                    heights[j] = 0;
                } else{
                    heights[j] += 1;
                }
            }
            area = std::max(area, largestRectangleArea(heights));
        }
        return area; 
    }

    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> s;
        s.push(-1);
        int area = 0;
        for(int i = 0; i < heights.size(); i++){
            while(s.top() != -1 && heights[i] < heights[s.top()]){
                int top = s.top();
                s.pop();
                int width = i - s.top() -1;
                area = std::max(area, width * heights[top]);
            }
            s.push(i);
        }
        while(s.top() != -1){
            int top = s.top();
            s.pop();
            int width = heights.size() -1 - s.top();
            area = std::max(area, width * heights[top]);
        }
        return area;   
    }
};