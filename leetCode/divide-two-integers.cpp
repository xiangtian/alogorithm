//LeetCode: 29
//2019-10-23
#include<iostream>
class Solution {
//每次都从2^0+2^1+...开始逼近，当快要接近被除数时。再从2^0+2^1+...开始逼近。直到不能更近为止
//另外一件比较不太好处理的就是边界问题
//2019-10-23
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }
        if (divisor == 1){
            return dividend;
        }
        int sign = (dividend > 0) ^ (divisor > 0); //判断除数和被除数是否同号
        unsigned int dividendU = dividend == INT_MIN ? INT_MAX + 1 : std::abs(dividend);//dividend取abs时会溢出
        unsigned int divisorU = divisor == INT_MIN ? INT_MAX +1 : std::abs(divisor);
        if (dividendU < divisorU)
        {
            return 0;
        }
        
        int sum = 0;
        unsigned int up = dividendU;
        while (up >= divisorU)
        {
            int count = 1;
            unsigned int base = divisorU;
            int maxBase = INT_MAX >> 1;
            while (base <= maxBase && (up > base << 1) )//base左移可能溢出
            {
                base <<= 1;
                count <<= 1;
            }
            sum += count;
            up -= base;
        }
        return sign ? -sum : sum;
    }
};