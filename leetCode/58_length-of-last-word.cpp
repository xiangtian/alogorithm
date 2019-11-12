#include<string>
class Solution {
//2019-11-11    
public:
    int lengthOfLastWord(std::string s) {
        if(s.length() == 0){
            return 0;
        }
        int end = s.length() -1;
        //找到第一个非空格字符
        while(end >=0 && s[end] == ' '){
            end--;
        }
        int i = 0;
        //从end开始找到第一空格字符
        while(end >=0 && s[end] != ' '){
            i++;
            end--;
        }
        return i; 
    }
};