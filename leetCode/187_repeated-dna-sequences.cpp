#include<vector>
#include<string>
#include<unordered_map>
class Solution {
//2019-11-14
//将子串放入map中、只在对应字符串次数超过1时，才加入到vector中
public:
    std::vector<std::string> findRepeatedDnaSequences(std::string s) {
        std::unordered_map<std::string, int> strMap;
        std::vector<std::string> result;
         if(s.length() < 10){
             return result;
        }
        for(int i = 0; i < s.length() - 9; i++){
            std::string tmp = s.substr(i, 10);
            if(strMap.find(tmp) == strMap.end()){
                strMap[tmp] = 1;
            } else{
                if(strMap[tmp] == 1){
                    result.push_back(tmp);
                }
                strMap[tmp]++;
            }
        }
        return result;   
    }
};