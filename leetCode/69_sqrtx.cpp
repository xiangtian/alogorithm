#include<iostream>
class Solution {
//2019-11-14
//从1到x进行二分查找，找对应的位置
public:
    int mySqrt(int x) {
        long low = 1;
        long high = x;
        while(low <= high){
            long mid = (low + high) / 2;
            long mul = mid * mid;
            if(mul > INT_MAX){
                high = mid -1;
                continue;
            }
            if(mul < x){
                low = mid + 1;
            } else if (mul > x){
                high = mid -1;
            } else {
                return mid;
            }
        }
        return low - 1;     
    }
};