//LeetCode: 7
//2019-10-15
#include<iostream>
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        //关键在于如何取得整数的最大和最小值和判断是否越界
        int max = std::numeric_limits<int>::max();
        int min = std::numeric_limits<int>::min();
        while(x != 0){
            int r = x % 10;
            x = x / 10;
            if(result > max / 10 || (result == max / 10 && r > max % 10)){
                return 0;
            }
            if(result < min / 10 || (result == min / 10 && r < min % 10 ))
            {
                return 0;
            }
             result = result * 10 + r;
        }
        return result;
    }
};