#include<vector>
class Solution {
//2019-11-19
//第i项为i ^ i >> 1
public:
    std::vector<int> grayCode(int n) {
        std::vector<int> result;
        for(int i = 0; i < 1 << n; i++){
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};