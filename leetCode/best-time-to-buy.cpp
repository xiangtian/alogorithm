//LeetCode: 121
//2019-10-17
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if(prices.size() <= 1){
            return 0;
        }

        int minPrice = prices[0];
        int maxEarn = 0;
        for(int i=1; i < prices.size(); i++){
            if (maxEarn < prices[i] - minPrice){
                maxEarn = prices[i] - minPrice;
            }
            if (minPrice > prices[i]){
                minPrice = prices[i];
            }
        }
        return maxEarn;
    }
};