#include<vector>
class Solution {
//2019-11-04
//依次找到为'.'的位置，检查1-9中能放入此位置的字符，放入后继续回溯。
//回溯结束的条件为循环到最后一个'.'的位置后，return true，层层回溯，并且不取出已经放入的值
public:
    void solveSudoku(std::vector<std::vector<char> >& board) {
          backtrack(board);
    }

    bool backtrack(std::vector<std::vector<char> >& board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(int k = 0; k < 9; k++){
                        char c = '1' + k;
                        if(isValid(i, j, c, board)){
                            board[i][j] = c;
                            bool solved = backtrack(board);
                            if(solved){
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    //检查当前char在此位置是否有效
    bool isValid(int row, int col, char c, std::vector<std::vector<char> >& board){
        for(int k = 0; k < 9; k++){
           if(board[row][k] == c ||board[k][col] == c){
               return false;
           }
        }
        int sRow = row / 3;
        int sCol = col / 3;
        for(int i = sRow * 3; i < (sRow+1) * 3; i++){
            for(int j = sCol * 3; j < (sCol+1) * 3; j++)
            {
                if(board[i][j] == c){
                    return false;
                }
            }
        }
        return true;
    }
};