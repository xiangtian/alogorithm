#include<vector>
#include<set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char> >& board) {
        //check rows;
        for(int i = 0; i < board.size(); i++){
            std::set<char> row;
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == '.') continue;
                if(row.find(board[i][j]) != row.end()) {
                    return false;
                } else {
                    row.insert(board[i][j]);
                }
            }
        }
        //check cols;
        for(int j = 0; j < board[0].size(); j++){
            std::set<char> col;
            for(int i=0; i < board.size(); i++){
                if(board[i][j] == '.') continue;
                if(col.find(board[i][j]) != col.end()) {
                    return false;
                } else {
                    col.insert(board[i][j]);
                }
            }
        }
         //check three square
        for(int k = 0; k < 3; k++){
            for(int m = 0; m < 3; m++){
                std::set<char> square;
                for(int i = k * 3; i < (k+1) * 3; i++){
                    for(int j = m * 3; j < (m+1) * 3; j++){
                        if(board[i][j] == '.') continue;
                        if(square.find(board[i][j]) != square.end()){
                            return false;
                        } else{
                            square.insert(board[i][j]);
                        }
                    }
                }
            }
        }
    }
};