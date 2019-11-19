#include<string>
#include<vector>
class Solution {
//2019-11-17
public:
    bool isAnagram(std::string s, std::string t) {
        std::vector<int> sCounts(26, 0);
        std::vector<int> tCounts(26, 0);
        for(int i = 0; i < s.length(); i++){
            sCounts[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            tCounts[t[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            if(sCounts[i] != tCounts[i]){
                return false;
            }
        }
        return true;
    }
};