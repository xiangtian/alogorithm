//LeetCode : 13
//2019-10-17
#include <string>
#include <map>
#include <iostream>
class Solution
{
//从前向后遍历，遇到不等的字符、判断后面字符的面值是否比当前的大、大则减，小则加
public:
    int romanToInt(std::string s)
    {
        std::map<char, int> m;
        m['M'] = 1000;
        m['D'] = 500;
        m['C'] = 100;
        m['L'] = 50;
        m['X'] = 10;
        m['V'] = 5;
        m['I'] = 1;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int j = i + 1;
            while (j < s.length() && s[i] == s[j])
            {
                j++;
            }
            int t = (j - i) * m[s[j - 1]];
            if (j < s.length() && m[s[j]] > m[s[j - 1]])
            {
                sum -= t;
            }
            else
            {
                sum += t;
            }
            i = j - 1;
        }
        return sum;
    }
};

int main()
{
    Solution s;
    std::cout << s.romanToInt("III") << std::endl;
    return 0;
}