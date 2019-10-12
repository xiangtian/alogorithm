//LeetCode:  5
#include <string>
#include <iostream>
class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        int start = 0, end = 0;
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int j = 1;
            //找到第一个不同的字符
            while ((i + j) < s.length() && s[i] == s[i + j])
            {
                if(maxLen <= j){
                    start = i;
                    end = i + j;
                    maxLen = j;
                }
                j++;
            }
            //获取相同字符最后一个位置
            j = j - 1;

            int k = 1;
            bool isPalindrome = false;
            //从当前字符和相同字符的最后一个位置，依次向两边搜索，不是回文时停止
            while ((i - k) >= 0 && (i + j + k) < s.length())
            {
                if (s[i - k] != s[i + j + k])
                {
                    break;
                }
                else
                {
                    int length = 2 * k + j + 1;
                    if (maxLen <= length)
                    {
                        start = i - k;
                        end = i + j + k;
                        maxLen = length;
                    }
                }
                k++;
            }
        }
    return s.substr(start, end - start + 1);
}
}
;

int main()
{
    Solution s;
    std::cout << s.longestPalindrome("abcb") << std::endl;
    std::cout << s.longestPalindrome("adbcbd") << std::endl;
    std::cout << s.longestPalindrome("dbcbd") << std::endl;
    std::cout << s.longestPalindrome("cabba") << std::endl;
    std::cout << s.longestPalindrome("cbbba") << std::endl;
    std::cout << s.longestPalindrome("bbb") << std::endl;
}