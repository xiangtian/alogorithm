#include<vector>
class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size() - 1; i >=0; i--){
            int sum = carry + digits[i];
            if(i == digits.size() - 1){
                sum += 1;
            }
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if(carry){
            digits.insert(digits.begin(), 1);
        }  
        return digits;     
    }
};