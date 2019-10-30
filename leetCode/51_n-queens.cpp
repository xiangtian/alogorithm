//LeetCode: 51
//2019-10-27
//回溯的经典问题
#include<vector>
#include<string>
class Solution {
//2019-10-27
//依次先把一个皇后放在第一行的某个位置后、放后续行的皇后时，需要检查当前皇后的需要放置的当前列
//当前元素所在的主对角线、当前元素的次对角线，是否已经有相应的元素，如果都没有则可以放下，否则
//探测下一列
//注：可以进一步的优化是，使用三个数组存储主对角线、次对角线、当前列是否有元素、可以效率
public:
   std::vector<std::vector<std::string> > solveNQueens(int n) {
   std::vector<std::vector<std::string> > result;
        std::vector<int> cols(n, 0);
        std::vector<std::vector<int> > chessboard(n, cols);
        backtrack(0, n, chessboard, result);
        return result;
    }

    void backtrack(int row, int n,
     std::vector<std::vector<int> >& cb,
     std::vector<std::vector<std::string> >& result){
        if(row > n -1){
            std::string s(n, '.');
            std::vector<std::string> r(n, s);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(cb[i][j] == 1){
                        r[i][j] = 'Q';
                        break;
                    }
                }
            }
            result.push_back(r);
            return;
        }

        for(int j = 0; j < n; j++){
            if(check(row, j, n, cb)){
                cb[row][j] = 1;
                backtrack(row+1, n, cb, result);
                cb[row][j] = 0;
            }
        }
    }

    bool check(int row, int col, int n, const std::vector<std::vector<int> > cb){
        //check该列上没有
         for(int i=0; i < row; i++){
            if(cb[i][col] == 1){
                return false;
            } 
        }
        //check左对角线
        for(int i = row -1, j = col -1; i >=0 && j>=0; i--, j--){
            if(cb[i][j] == 1){
                return false;
            }
        }
        //check右对角线
        for(int i = row -1, j = col + 1; i >=0 && j < n; i--, j++){
            if(cb[i][j] == 1)
            {
                return false;
            }
        }
        return true;
    }
};