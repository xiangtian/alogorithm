//LeetCode: 51
//2019-10-27
//回溯的经典问题
#include<vector>
#include<string>
class Solution {
//在n皇后的问题上，一旦有合适的结果，将结果数+1即可
public:
    int totalNQueens(int n) {        
        int sum = 0;
        std::vector<int> cols(n, 0);
        std::vector<std::vector<int> > chessboard(n, cols);
        backtrack(0, n, chessboard, sum);
        return sum;
    }

    void backtrack(int row, int n, std::vector<std::vector<int> >& cb, int& result){
        if(row > n -1){
            result++;
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