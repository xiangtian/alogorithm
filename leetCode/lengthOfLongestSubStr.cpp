//LeetCode: 3
#include <iostream>
#include <string>
#include <map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int maxLength = 0;
        int length = 0;
        int lastIdx = 0;
        std::map<char, int> chars;
        for (int i = 0; i < s.length(); i++)
        {
            std::map<char, int>::const_iterator it = chars.find(s[i]);
            if (it != chars.end())
            {
                int idx = it->second;
                while (lastIdx <= idx)
                {
                    chars.erase(chars.find(s[lastIdx]));
                    lastIdx++;
                }
                chars[s[i]] = i;
                length = chars.size();
            }
            else
            {
                chars[s[i]] = i;
                length++;
            }
            if (maxLength < length)
            {
                maxLength = length;
            }
        }
        return maxLength;
    }
};