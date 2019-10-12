//LeetCode: 9
#include<vector>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        std::vector<int> digits;
        while(x){
            digits.push_back(x % 10);
            x /= 10;
        }
     
        for(int i = 0, j; i < digits.size() && i<=j; i++){
            j = digits.size() - 1 - i;
            if(digits[i] != digits[j]){
                return false;
            } 
        }
        return true; 
    }
};