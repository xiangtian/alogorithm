#include<string>
#include<vector>
class Solution {
//2019-11-26
//nums[i][j]表示s1用了i个元素、s2用了j个元素后是否与s3的s3[i+j-1]的元素相等
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        std::vector<bool> cols(s2.length() + 1, false);
        std::vector<std::vector<bool> > rows(s1.length() + 1, cols);
        for(int i = 0; i <= s1.length(); i++){
            for(int j = 0; j <= s2.length(); j++){
                if(i == 0 && j == 0){
                    rows[i][j] = true;
                } else if(i == 0){
                    rows[i][j] = rows[i][j-1] && s2[j-1] == s3[j -1]; 
                } else if(j == 0){
                    rows[i][j] = rows[i-1][j] && s1[i-1] == s3[i-1];
                } else {
                    rows[i][j] = (rows[i-1][j] && s1[i-1] == s3[i+j-1]) || (rows[i][j-1] && s2[j-1]== s3[i+j-1]);
                }
            }
        }
        return rows[s1.length()][s2.length()];   
    }
};