//LeetCode: 60
//2019-11-03
#include<string>
#include<vector>
class Solution {
//第一种依次计算出1到n的阶乘，然后用k-1依次除以n-1位的阶乘、然后从nums中取出对应的数字
public:
    std::string getPermutation(int n, int k) {
       std::vector<int> fac;
        fac.push_back(1);
        for(int i = 1; i <= n; i++){
            fac.push_back(i* fac[i-1]);
        }
        std::vector<int> nums;
        for(int i = 0; i < n; i++){
            nums.push_back(i+1);
        }

        std::string result;
        k = k -1;//将k-1是我没有想到的方式
        while(n--){
            int pos = k / fac [n]; //k先除以f[n-1],从而取出对应位置的数，将取出的数移除
            char c = '0' +nums[pos];
            result.push_back(c);
            nums.erase(nums.begin() + pos);
            k %= fac[n];
        }
        return result;  
    }
    
    //第二种方式通过回溯来计数是否到达第K位
    std::string getPermutationII(int n, int k) {
        std::vector<bool> pos(n, false);
        std::string result;
        std::string tmp;
        backtrack(n, k, tmp, pos, result); 
        return result;
    }

    void backtrack(int n,
                   int &k,
                   std::string &tmp,
                   std::vector<bool> &pos,
                   std::string &result)
    {
        if(tmp.length() == n){
            k--;
            if(k==0){
                result = tmp;//当k == 0时，保存结果。
            }
            return;
        }
        
        for(int i = 1; i <=n; i++){
            if (k){//当k不等于0时才进行递归和for循环
                if(pos[i]){
                    continue;
                }
                char c = i + '0';
                pos[i] = true;
                tmp.push_back(c);
                backtrack(n, k, tmp, pos, result);
                tmp.pop_back();
                pos[i] = false;
            } else{
                break;
            }
        }
    }

};