//LeetCode: 14
//2019-10-16
#include<vector>
#include<string>
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string result;
        for(int i = 0; i < strs[0].length(); i++)
        {
            for(int j=1; i < strs.size(); j++){
                if(i >= strs[j].length() || strs[j][i] !=strs[0][i]){
                    return result;
                }

            }
            result.push_back(strs[0][i])
        }
        return result;
    }
};