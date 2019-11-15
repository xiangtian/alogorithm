#include<vector>
class Solution {
//2019-11-13
//针对当前值的差进行二分查找
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> result;
        int i = 0, j = numbers.size() - 1;
        while(i < j ){
            if(numbers[i] + numbers[j] > target){
                j--;
            }else if (numbers[i] + numbers[j] < target){
                i++;
            } else {
                result.push_back(i + 1);
                result.push_back(j + 1);
                break;
            }
        }
        return result;
    }
};