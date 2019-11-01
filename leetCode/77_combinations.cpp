#include<vector>
class Solution {
//2019-11-01
//回溯，从1开始依次放入数组
public:
    std::vector<std::vector<int> > combine(int n, int k) {
        std::vector<std::vector<int> > result;
        std::vector<int> tmp;
        backtrack(1, n, k, tmp, result);
        return result;
    }

    void backtrack(int idx, int n, int k, 
                   std::vector<int>& tmp, 
                   std::vector<std::vector<int> >& result){
        if(tmp.size() == k){
            result.push_back(tmp);
            return;
        }
        
        for(int i = idx; i<= n; i++){
            tmp.push_back(i);
            backtrack(i+1, n, k, tmp, result);
            tmp.pop_back();
        }
    }
};