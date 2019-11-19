class Solution {
//2019-11-17
public:
    int addDigits(int num) {
        while(num >= 10){
            int count = 0;
            while(num){
                count+= num % 10;
                num= num /10;
            }
            num = count;
        }
        return num;
        
    }
};