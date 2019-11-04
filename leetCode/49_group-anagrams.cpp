#include<vector>
#include<string>
#include<unordered_map>
class Solution {
public:
    std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string> > result;
        std::unordered_map<std::string, std::vector<std::string> > m;
        for(int i = 0; i < strs.size(); i++){
            std::string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(strs[i]);
        }

        for(typeof(m.begin()) it = m.begin(); it != m.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
};