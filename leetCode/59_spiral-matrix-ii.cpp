//LeetCode: 59
//2019-11-11
#include<vector>
class Solution {
public:
    std::vector<std::vector<int> > generateMatrix(int n) {
        std::vector<int> row(n, -1);
        std::vector<std::vector<int> > matrix(n, row);
        int r1 = 0, r2 = n - 1;
        int c1 = 0, c2 = n - 1;
        int count = 1;
        while(r1 <= r2 && c1 <= c2){
            for(int j = c1; j <= c2; j++){
                matrix[r1][j] = count++;
            }
            for(int i = r1; i <= r2; i++){
                matrix[i][r2] = count++;
            }
            if(r1 < r2 && c1 < c2){
                for(int j = c2 -1; j >= c1; j--){
                    matrix[r2][j] = count++;
                }
                for(int i = r2 -1; i > r1; i--){
                    matrix[i][c1] = count++;
                }
            }
        }
        return matrix;  
    }
};