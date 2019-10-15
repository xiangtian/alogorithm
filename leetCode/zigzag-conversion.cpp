//LeetCode: 6
//2019-10-14
//依次遍历string中的char、设置flag进行反转
#include <string>
#include <vector>
#include <iostream>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1){
            return s;
        }
        std::vector<std::string> result(numRows);
        bool flag = true;
        for (int i = 0, k = 0; i < s.length(); i++)
        {
           if(flag && k < numRows){
               result[k++].push_back(s[i]);
               if(k == numRows){
                   flag = false;
                   k-= 2;
               }
               continue;
           }

           if(!flag && k >= 0){
               result[k--].push_back(s[i]);
               if(k < 0){
                   flag = true;
                   k = 1;
               }
           }
        }
        
        std::string rs;
        for (int i = 0; i < numRows; i++){
            rs += result[i];
        }
        return rs;
    }
};

int main(){
    Solution s;
    std::cout << s.convert("PAYPALISHIRING",3) << std::endl;
    std::cout << s.convert("AB", 1) << std::endl;

    return 0;
}
