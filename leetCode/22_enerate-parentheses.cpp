#include<vector>
#include<string>
class Solution {
//2019-10-30
//使用递归来解决
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result; 
        backtrack(n, n, "", result);
        return result;
    }

    void backtrack(int left, int right, std::string s, std::vector<std::string>& result){
        if(left > right){//剩余的左括号大于右括号数
            return;
        }
        if(left == 0 && right == 0){
            result.push_back(s);
            return;
        }
        if(left > 0){
            backtrack(left -1, right, s+"(", result);
        }
        
        if(right > 0){
            backtrack(left, right -1, s + ")", result);
        }
    }

private:
    //2019-10-31
    //使用回溯的方法、左括号没有放满就先放左括号，放完之后放右括号
    std::vector<std::string> generateParenthesis2(int n){
        std::vector<std::string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    void backtrack(std::vector<std::string>& result, std::string s,  int left, int right, int max){
        if(s.length() == 2 * max){
            result.push_back(s);
        }
        
        if(left < max){
            backtrack(result, s+"(", left+1, right, max);
        }

        if(right < left){
            backtrack(result, s+")", left, right+1, max);
        }
    }
};