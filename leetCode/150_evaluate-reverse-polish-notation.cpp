#include<vector>
#include<stack>
#include<string>
class Solution {
//2019-11-22
//当遇到运算符时，出栈两个数进行计算
//主要是字符串和整数之间的转换
public:
    int evalRPN(std::vector<std::string>& tokens) {
        int sum = 0;
        std::stack<std::string> s;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                s.push(tokens[i]);
            } else{
                op(s, tokens[i]);
            }
        }
        return atoi(s.top().c_str());
    }

    void op(std::stack<std::string>& s, std::string& token){
        int first = atoi(s.top().c_str());
        s.pop();
        int second = atoi(s.top().c_str());
        s.pop();
        int result = 0;
        if(token == "+"){
            result = first + second;
        }else if(token == "-"){
            result = second - first;
        } else if (token == "*"){
            result = first * second;
        } else {
            result = second / first;
        }

        std::stringstream ss;
        ss << result;
        s.push(ss.str());
    }
};