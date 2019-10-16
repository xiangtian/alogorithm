//LeetCode: 12
//2019-10-17
#include <string>
#include <map>
class Solution
{
//直接穷举所有的Case即可，使用factor的方式，代码看起来更清楚一些
public:
    std::string intToRoman(int num)
    {
        std::string result;
        std::map<int, std::string> m;
        m[1000] = "M";
        m[500] = "D";
        m[100] = "C";
        m[50] = "L";
        m[10] = "X";
        m[5] = "V";
        m[1] = "I";
        int factor = 1000;
        while (factor)
        {
            int h = num / factor;
            if (h <= 3)
            {
                for (int i = 0; i < h; i++)
                {
                    result.append(m[factor]);
                }
            }
            else if (h == 4)
            {
                result.append(m[factor]);
                result.append(m[factor * 5]);
            }
            else if (h <= 8)
            {
                result.append(m[factor * 5]);
                for (int i = 0; i < (h - 5); i++)
                {
                    result.append(m[factor]);
                }
            }
            else
            {
                result.append(m[factor]);
                result.append(m[factor * 10]);
            }
            num = num % factor;
            factor /= 10;
        }
        return result;
    }
};