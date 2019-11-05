#include<string>
#include<iostream>
#include<vector>
class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        if(num1.length() > num2.length()){
            return mul(num2, num1);
        }
        return mul(num1, num2);
    }

    std::string mul(const std::string& left, const std::string& right){
        std::vector<int> result;
        std::vector<int> tmp;
        for(int i = left.length() -1; i >= 0; i--){
            for(int k = i; k < left.length() -1; k++){
                tmp.push_back(0);
            }
            int d1 = left[i] - '0';
            int carry = 0;
            for(int j = right.length() -1; j >=0; j--){
                int d2 = right[j] - '0';
                int sum  = carry + d1 * d2;
                tmp.push_back( sum % 10 );
                carry = sum / 10;
            }
            if(carry){
                tmp.push_back(carry);
            }
            result = add(result, tmp);
        }
        std::string r;
        for(int i = result.size() -1; i >= 0; i--){
            r.push_back(i + '0');
        }
        return r;
    }

    std::vector<int> add(const std::vector<int> up, const std::vector<int>& down){
        std::vector<int> ret;
        int i = 0, j = 0;
        int carry = 0;
        while(i < up.size() && j < down.size()){
            int sum = up[i] + down[j] + carry;
            ret.push_back(sum % 10);
            carry = sum / 10;
            i++, j++;
        } 

        while( i < up.size()){
            int sum = up[i]  + carry;
            ret.push_back(sum % 10);
            carry = sum / 10;
            i++;
        }

        while(j < down.size()){
            int sum = down[j]  + carry;
            ret.push_back(sum % 10);
            carry = sum / 10;
            j++;
        }
    
        if(carry){
            ret.push_back(carry);
        }
        return ret;
    }

        
};