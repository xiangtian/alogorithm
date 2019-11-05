#include<vector>
class Solution {
//2019-11-04
//动态规划的状态方程加了条件判断
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int> >& obstacleGrid) {
        if(obstacleGrid[obstacleGrid.size() -1][obstacleGrid[0].size() - 1] == 1){
            return 0;
        }//注意最后一格为1的情况
        
        std::vector<long> cols(obstacleGrid[0].size(), 0);
        std::vector<std::vector<long> > pos(obstacleGrid.size(), cols);
        for(int i = 0; i < obstacleGrid.size(); i++){
            for(int j = 0; j < obstacleGrid[0].size(); j++){
                if(i == 0 && j == 0){
                    if(obstacleGrid[i][j] == 1){
                        return 0;
                    } else{
                        pos[i][j] = 1;
                    }
                } else if(i == 0){
                    if(obstacleGrid[i][j-1] == 1 || pos[i][j-1] == 0){
                        pos[i][j] = 0;
                    } else {
                        pos[i][j] = 1;
                    }
                } else if (j == 0){
                    if(obstacleGrid[i-1][j] == 1 || pos[i-1][j] == 0){
                        pos[i][j] = 0;
                    } else {
                        pos[i][j] = 1;
                    }
                } else{
                    long left = obstacleGrid[i][j-1] == 1 ? 0 : pos[i][j-1];
                    long up = obstacleGrid[i-1][j] == 1 ? 0: pos[i-1][j];
                    pos[i][j] = left + up;
                }
            }
        }
        return pos[obstacleGrid.size() -1][obstacleGrid[0].size() - 1]; 
    }
};