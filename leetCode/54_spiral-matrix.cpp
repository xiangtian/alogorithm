#include<vector>
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int> >& matrix) {
        std::vector<int> result;
        if(matrix.size() == 0){
            return result;
        }
        int r1 = 0, r2 = matrix.size() -1;
        int c1 = 0, c2 = matrix[0].size() -1;
        while(r1 <= r2 && c1 <= c2){
            for(int j = c1; j <=c2; j++){
                result.push_back(matrix[r1][j]);
            }
            for(int i = r1 + 1; i <=r2; i++){
                result.push_back(matrix[i][c2]);
            }
            if(c1 < c2 && r1 < r2){
                for(int j = c2 -1; j >= c1; j--){
                    result.push_back(matrix[r2][j]);
                }
                for(int i = r2 -1; i > r1; i--){
                    result.push_back(matrix[i][c1]);
                }
            }
            
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return result;  
    }
};