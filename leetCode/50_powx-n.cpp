#include<iostream>
class Solution {
//2019-11-04
//使用乘法来完成x的n次方
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0;
        }
        else if(n == INT_MIN){//注意边界条件
            return 1 / x * myPow(x, -INT_MAX);
        }
        else if(n < 0){
            return 1 / myPow(x, -n);
        }

        double mid = myPow(x, n / 2);
        double result = 1;
        if(n & 1){//n为奇数
            return  mid * mid * x;
        } 
         return mid * mid;
    }
};