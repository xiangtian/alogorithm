//leetCode: 20
//2019-10-27
#include<iostream>
#include<stack>
class Solution {
//使用栈来遍历一遍即可
public:
    bool isValid(std::string s) {
        std::stack<char> brackets;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                brackets.push(s[i]);
                continue;
            }
            if(brackets.size() == 0){//只有右括号的时候
                return false;
            }
            char c = brackets.top();
            if((c == '('&& s[i] == ')') || (c=='{' && s[i] =='}') || (c=='['&&s[i] == ']')){
                brackets.pop();
            } else{
                return false;
            }
        }   
        if(brackets.size() != 0){
            return false;
        } 
        return true;
    }
};