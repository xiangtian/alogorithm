#include<string>
#include<algorithm>
class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        int i = a.length() -1; 
        int j = b.length() -1;
        int carry = 0;
        std::string result;
        while(i >=0 && j >=0){
            int sum = a[i] -'0' + b[j] -'0'+ carry;
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
            i--;
            j--;
        }
        
        while(i >=0){
            int sum = a[i] -'0' + carry;
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
            i--;
        }

        while(j >=0){
            int sum = b[j] - '0' + carry;
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
            j--;
        }
        
        if(carry){
            result.push_back(1 + '0');
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};