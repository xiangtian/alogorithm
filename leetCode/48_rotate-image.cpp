#include<vector>
class Solution {
public:
    void rotate(std::vector<std::vector<int> >& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i; j < matrix[0].size(); j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        
        int rowLength = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < rowLength / 2; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][rowLength -1 -j];
                matrix[i][rowLength -1 -j] = matrix[i][j];
            }
        }
        
       
        
    }
};