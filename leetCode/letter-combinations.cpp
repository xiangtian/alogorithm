//LeetCode: 17
//2019-10-16
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<list>
class Solution {
// 2019-10-16
// 使用queue或者list来进行广度优先遍历
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::map<char, std::string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        std::vector<std::string> result;
        if (digits.size() == 0){
            return result;
        }

        std::list<std::string> q;
        for(int i = 0; i < m[digits[0]].length(); i++){
            q.push_back(std::string(1,m[digits[0]][i]));
        }
        for(int i = 1; i < digits.length(); i++){
            int size = q.size();
            std::string chars = m[digits[i]];
            while(size--){
                std::string front = q.front();//使用Queue进行广度优先遍历
                for(int j = 0; j < chars.length(); j++)
                {
                    std::string s = front + std::string(1, chars[j]);
                    q.push_back(s);
                }
                q.pop_front();  
            }
        }
       
        for (std::list<std::string>::iterator it = q.begin(); it != q.end(); it++){
            result.push_back(*it);;
        }
       return result;
    }
};

int main(){
    Solution s;
    std::vector<std::string> v = s.letterCombinations("23");
    for (int i = 0; i < v.size(); i++){
        
        std::cout << v[i] << std::endl;
    }
    return 0;
}