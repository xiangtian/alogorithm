//LeetCode: 62
////2019-10-18
#include<vector>
class Solution {
//当前元素的路径数等于上方的路径数 + 左方的路径数
//状态方程s[i][j] = s[i-1][j] + s[i][j-1]
public:
    int uniquePaths(int m, int n) {
        if(m < 1 || n < 1){
            return 0;
        }
        std::vector<int> v(n, 0);
        std::vector<std::vector<int> > vv(m, v);
        int i = 0; 
        int j = 0;
        while(i < m && j < n){
            if(i == 0 && j == 0){
                for(int k = j; k < n; k++){
                    vv[i][k] = 1;
                }
                for(int k = i+1; k < m; k++){
                    vv[k][j] = 1;
                }
            } else {
                for(int k = j; k < n; k++){
                    vv[i][k] = vv[i-1][k] + vv[i][k-1];
                }
                for(int k = i+1; k < m; k++){
                    vv[k][j] = vv[k-1][j] + vv[k][j-1];
                }
            }
            i++;
            j++;
        }
        return vv[m-1][n-1];
    }
};