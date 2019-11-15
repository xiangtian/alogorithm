#include<vector>
class Solution {
//2019-11-13
public:
    std::vector<std::vector<int> > generate(int numRows) {
        std::vector<std::vector<int> > result;
        std::vector<int> row1;
        row1.push_back(1);
        std::vector<int> row2;
        row2.push_back(1);
        row2.push_back(1);
        if(numRows == 0){
            return result;
        } else if(numRows == 1){
           result.push_back(row1);
        } else if (numRows == 2){
            result.push_back(row1);
            result.push_back(row2);
        } else {
            result.push_back(row1);
            result.push_back(row2);
            for(int i = 2; i <= numRows -1; i++){
                std::vector<int> row;
                row.push_back(1);
                for(int j = 1; j < result[i-1].size(); j++){
                    row.push_back(result[i-1][j] + result[i-1][j-1]);
                }
                row.push_back(1);
                result.push_back(row);
            }
        }
        return result;  
    }
};