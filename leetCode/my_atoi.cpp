//LeetCode: 8
//2019-10-15
#include <string>
#include "limits.h"
class Solution {
//1、处理开头的空格 2、处理‘+’和‘-’ 3、处理最大最小数限制 4、isdigit和char转整数的做法
public:
    int myAtoi(std::string str) {
        int i = 0;
        while( str[i] == ' '){
            i++;
        }
        if(str[i] !='-' && str[i] !='+' && !isdigit(str[i])) {
          return 0;
        }
       int factor = 1;
       if(str[i] == '-' || str[i] == '+'){
            factor = str[i] == '-' ? -1 : 1;
            i++;
       }
       int result = 0;
       while(isdigit(str[i])){
           int r = factor * int(str[i]-'0');
           if(factor == 1 && (result > INT_MAX / 10 || (result == INT_MAX / 10 && r > INT_MAX %  10)))            {
               return INT_MAX;
           }
           if(factor == -1 && (result < INT_MIN / 10 || (result == INT_MIN / 10 && r < INT_MIN % 10)))            {
               return INT_MIN;
           }
           result = result * 10 + r;
           i++;
       }
       return result;
        
    }
};