//LeetCode: 233
//2019-11-05
#include<iostream>
class Solution {
//依次判断最后一个位的值为: 0, 1, >=1等等
//最后一位为0时，1的个数只有高位决定
//最后一位为1时，1的个数由高位和低位共同决定
//最后一位为大于1的数时，（高位 + 1) * factor
public:
    int countDigitOne(int n) {
       if (n < 0){
            return 0;
        }
        int current = 0;
        int high = 0;
        int count = 0;
        int low = 0;
        long factor = 1;
        int num = n;
        while(num){
            high = num / 10;
            current = num % 10;
            low = n % factor; // 注意是n对于当前的factor取余数
            if(current == 0){
                count += high * factor;
            } else if (current ==1){
                count += high * factor + low + 1;
            } else{
                count += (high + 1) * factor;
            }
            num = num / 10;
            factor *= 10;
        }
        
        return count;  
    }
};