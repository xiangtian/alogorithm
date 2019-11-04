//LeetCode: 38
//2019-11-04
#include<string>
class Solution {
//2019-11-04
//使用计数器来计算当前位的个数，当遇到第一个不同的值时，将count重新置为1 
public:
    std::string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        std::string result("1");
        for(int i = 1; i < n; i++){
            int count = 1;
            std::string s;
            for(int j = 0; j < result.size(); j++){
                if((j+1) < result.size() && result[j] != result[j+1]){
                    s.push_back('0' + count);
                    s.push_back(result[j]);
                    count = 1;
                } else {
                    if(j+1 == result.size()){
                        s.push_back('0' + count);
                        s.push_back(result[j]);
                        count = 1;
                    } else{
                        count++;
                    }
                }
            }
            result = s;
        }
        return result; 
    }
};