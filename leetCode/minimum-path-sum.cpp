//LeetCode: 64
////2019-10-18
#include<vector>
class Solution {
//当前元素的路径最小值等于min（当前元素的上方的元素的路径最小值，当前元素左方的路径最小值） + 当前元素
//状态方程 r[i][j] = min(r[i-1][j], r[i][j-1]) + grid[i][j]
public:
    int minPathSum(std::vector<std::vector<int> >& grid) {
        if(grid.size() == 0){
            return 0;
        }

        int i = 0,j = 0;
        std::vector<int> v(grid[0].size(), 0);
        std::vector<std::vector<int> > vv(grid.size(), v);
        int m = grid.size();
        int n = grid[0].size();
        while(i < grid.size() && j < grid[i].size()){
            if(i == 0 && j == 0){
                vv[0][0] = grid[0][0];
                for(int k = j+1; k < n; k++){//最上面一行
                    vv[i][k] = vv[i][k-1] + grid[i][k];
                }
                for(int k = i+1; k < m; k++){//最左列
                    vv[k][j] = vv[k-1][j] + grid[k][j];
                }
            } else {
                for(int k = j; k < n; k++){
                    vv[i][k] = std::min(vv[i-1][k],vv[i][k-1]) + grid[i][k];
                }
                for(int k = i+1; k < m; k++){
                    vv[k][j] = std::min(vv[k-1][j], vv[k][j-1]) + grid[k][j];
                }
            }
            i++;
            j++;
        }
        return vv[grid.size() -1][grid[0].size() -1];
    }
};