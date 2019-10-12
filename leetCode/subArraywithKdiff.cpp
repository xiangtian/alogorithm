//LeetCode 992
#include <vector>
#include <iostream>
#include <map>
class Solution
{
public:
    void printMap(std::map<int, int> &m)
    {
        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
        {
            std::cout << it->first << " => " << it->second << " ";
        }
        std::cout << std::endl;
    }

    void addToMap(std::map<int, int> &m, int item)
    {
        std::map<int, int>::iterator it = m.find(item);
        if (it != m.end())
        {
            it->second++;
        }
        else
        {
            m[item] = 1;
        }
    }

    void deleteFromMap(std::map<int, int> &m, int item)
    {
        std::map<int, int>::iterator it = m.find(item);
        if (it != m.end())
        {
            it->second--;
            if (it->second == 0)
            {
                m.erase(it);
            }
        }
    }

    int subarraysWithKDistinct(std::vector<int> &A, int K)
    {
        int subArrayCount = 0;
        std::map<int, int> diffs1;
        std::map<int, int> diffs2;
        int left1 = 0, left2 = 0;
        for (int right = 0; right < A.size(); right++)
        {
            addToMap(diffs1, A[right]);
            addToMap(diffs2, A[right]);

            while (diffs1.size() > K)
            {
                deleteFromMap(diffs1, A[left1++]);
            }

            while (diffs2.size() >= K)
            {
                deleteFromMap(diffs2, A[left2++]);
            }

            subArrayCount += left2 - left1;
        }
        return subArrayCount;
    }
};

int main()
{
    Solution s;
    std::vector<int> m;
    m.push_back(1);
    m.push_back(2);
    m.push_back(1);
    m.push_back(2);
    m.push_back(3);
    std::cout << s.subarraysWithKDistinct(m, 2) << std::endl;
    return 0;
}