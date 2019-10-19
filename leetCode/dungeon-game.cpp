#include<vector>

class Solution {
public:
//逆向动态规划问题、从右下角向左上角推理
//2019-10-19
    int calculateMinimumHP(std::vector<std::vector<int> >& dungeon) {
        if(dungeon.size() == 0){
            return 1;
        }
        std::vector<int> v(dungeon[0].size());
        std::vector<std::vector<int> > vv(dungeon.size(), v);
        int m = dungeon.size();
        int n = dungeon[0].size();
        int i = m -1,j = n -1;
        for(int i = m -1; i >=0; i--){
            for(int j = n -1; j >=0; j--){
                if(i== m -1 && j == n-1){
                    //右下角如果为正，只需要1、如果为负数，则需要-dungeon[i][j] +1
                    vv[i][j] = std::max(1, 1-dungeon[i][j]);
                } else if(i== m-1){
                    //最后一行
                    vv[i][j] = std::max(1, vv[i][j+1]-dungeon[i][j]);
                } else if(j == n-1){
                    //最后一列
                    vv[i][j] = std::max(1, vv[i+1][j] - dungeon[i][j]);
                } else{
                    //其它情况
                    vv[i][j] = std::max(1, std::min(vv[i][j+1], vv[i+1][j]) - dungeon[i][j]);
                }
            }
        }
        return vv[0][0];  
        
    }
};
};