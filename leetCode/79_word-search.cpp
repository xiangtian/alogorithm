#include<vector>
#include<string>

class Solution {
public:
    bool exist(std::vector<std::vector<char> >& board, std::string word) {
          if(board.size() == 0){
            return false;
        }
        if(word.length() == 0){
            return true;
        }
        //存储位置是否访问过
        std::vector<bool> cols(board[0].size(), false);
        std::vector<std::vector<bool> > pos(board.size(), cols);
        //可以算优化
        std::vector<std::pair<int, int> > firstPos;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    firstPos.push_back(std::make_pair(i, j));
                }
            }
        }
        //没有word的首字母
        if(firstPos.size() ==0){
            return false;
        }
        std::string tmp;
        //从找出的首字母中开始回溯
        for(int i =0; i < firstPos.size(); i++){
            if(backtrack(firstPos[i].first, firstPos[i].second, 0, tmp, board, pos, word)){
                return true;
            }
        }
        return false;  
    }

    bool backtrack(int i,
                   int j,
                   int k,//当前位置的字符是否相等
                   std::string& tmp,
                   const std::vector<std::vector<char> > &board,
                   std::vector<std::vector<bool> > &pos,
                   const std::string &word)
    {
         if(tmp.length() == word.length()){
            if(tmp == word){
                return true;
            }
            return false;
        }

        //越界、已经填充过就停止回溯
        if(i < 0 || j < 0 || i > board.size() -1 
        || j > board[0].size()-1 || pos[i][j]){
            return false;
        }
        tmp.push_back(board[i][j]);
        pos[i][j] = true;
        //对上下左右四个方向进行回溯,判断当前字符相等时，才进行下一次回溯
        bool exist = tmp[k] == word[k] && 
            (backtrack(i - 1, j, k+1, tmp, board, pos, word)
            || backtrack(i, j - 1, k+1, tmp, board, pos, word) 
            || backtrack(i + 1, j, k+1, tmp, board, pos, word)
            || backtrack(i, j + 1,  k+1,tmp, board, pos, word)
            );
        tmp.pop_back();
        pos[i][j] = false;
        return exist;
    }
};