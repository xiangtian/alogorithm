//LeetCode: 70
//2019-10-18
class Solution {
public:
//状态方程f(n) = f(n-1) + f(n-2)
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        int first = 1;
        int second = 2;
        int third = 0;
        for(int i = 3; i < n; i++){
            third = first + second;
            first = second;
            second = third;
        }
        return third;  
    }
};