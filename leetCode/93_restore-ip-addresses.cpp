#include<vector>
#include<string>
class Solution {
//2019-11-26
public:
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> result;
        std::string temp;
        backtrack(s, temp, 0, result);
        return result;
    }

    void backtrack(std::string s, std::string& temp, int wordNum, std::vector<std::string>& result){
        if(wordNum == 4){
            //wordNum == 4 时， s字符串不为空。
            if(s.size() == 0){
                result.push_back(temp);
            }
            return;
        }
        
        if(wordNum > 0){
            temp.push_back('.');
        }
        for(int i = 1; i <= 3 && i <=s.length(); i++){//".可以放在第1-3位"
            std::string sub = s.substr(0, i);
            if(valid(sub)){
                temp += sub;
                backtrack(s.substr(i, s.length() -1), temp, wordNum+1, result);
                temp.erase(temp.size() - i, i);
            }
        }
        temp.pop_back(); 
    }

    bool valid(const std::string& subIp){
        //判断截取的ip值是否合法，长度大于1时，首字母不可为0
        if(subIp.empty() || (subIp[0] == '0' && subIp.size() > 1)){
            return false;
        }
        int val = std::stoi(subIp);//stoi是c++ 11中引入的内容
        if(val >= 0 && val <= 255) return true;
        return false;
    }
};