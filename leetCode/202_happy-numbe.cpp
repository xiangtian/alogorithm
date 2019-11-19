#include<set>
//2019-11-14
//使用set来判断是否有循环计算的情况
class Solution {
public:
    bool isHappy(int n) {
        std::set<int> used;
        used.insert(n);
        while(true){
            int sum = 0;
            while(n){
                int r = n % 10;
                sum += r * r;
                n/=10;
            }
            if(sum == 1){
                return true;
            } else {
                if(used.find(sum) != used.end()){
                    return false;
                } else{
                    used.insert(sum);
                    n = sum;
                }
            }
        }
        return false;  
    }
};