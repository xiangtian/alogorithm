//LeetCode: 15
//2019-10-14
#include<vector>
#include<map>
#include<set>
#include<iostream>

class Solution {
//先排序、然后使用左右指针从两头向中间遍历
public:
    std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int> > result;
        sort(nums.begin(), nums.end());//排序
        for(int i = 0; i< nums.size(); i++){//时间复杂度n^2
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size() -1;
            while(left < right){
                if(nums[left] + nums[right] + nums[i] > 0){
                    right--;
                } else if (nums[left] + nums[right] + nums[i] < 0){
                    left++;
                } else{
                    std::vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[left]);
                    v.push_back(nums[right]);
                    result.push_back(v);
                    ++left;
                    --right;
                    while(left< right && nums[left]== nums[left-1]) ++left;//去重
                    while(left < right && nums[right] == nums[right+1]) --right; //去重
                }
            }
        }
        return  result;
    }
};

int main(){
    int a[] = {-1,0,1,2,-1,-4};
    std::vector<int> v(a, a+6);
    Solution s;
    std::vector<std::vector<int> > r = s.threeSum(v);
    for(int i = 0; i < r.size(); i++){
        for(int j = 0; j < r[i].size(); j++){
            std::cout << r[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}