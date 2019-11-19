#include<string>
#include<vector>
class Solution {
//2019-11-19
//动态规划有条件的转换方程
//s[i] == '0'时，只能和s[i-1]进行结合s[i] = s[i-2], 不能结合则不能破解
//s[i] <= '6' && s[i-1] == '2' )|| s[i-1] == '1'时，
//s[i] = s[i-1] + s[i-2], i=1时，s[i-2]可能不存在，s[i] = s[i-1] + 1
//其他的情况s[i] = s[i-1]
public:
    int numDecodings(std::string s){
        //length == 0或者length >=1 && s[0] == '0'时无解
        if(s.length() == 0 || (s.length() >= 1 && s[0] == '0')){
            return 0;
        }
       
        std::vector<int> dp(s.length(), 0);
        dp[0] = 1;
        for(int i = 1; i  < s.length(); i++){
            if (s[i] == '0'){
                if (s[i - 1] != '1' && s[i - 1] != '2'){
                    return 0;
                } else {
                    dp[i] = i >= 2 ? dp[i - 2]: 1;//只能和s[i-1]结合才能解码
                }
            } else{
                if((s[i] <= '6' && s[i-1] == '2' )|| s[i-1] == '1'){
                    int tmp = i >= 2 ? dp[i-2]: 1;
                    dp[i] = dp[i-1] + tmp;//当前元素即可独立解码，又可结合前一个元素解码
                } else{
                    dp[i] = dp[i-1];
                }

            }
        }
        return dp.back();
    }

    int numDecodingsII(std::string s) {
        if(s.length() == 0 || (s.length() == 1 && s[0] == '0')){
            return 0;
        }
        if(s.length() == 1){
            return 1;
        }
        std::vector<int> dp(s.length()+ 1, 0);
        dp[0] = 1;
        for(int i = 0; i < s.length(); i++){
            dp[i+1] = s[i] == '0' ? 0 : dp[i];
            if(i > 0 && (s[i-1] == '1'||s[i-1] == '2') && s[i] <= '6'){
                dp[i+1] += dp[i-1];
            }    
        } 
        return dp.back();
    }
    
};