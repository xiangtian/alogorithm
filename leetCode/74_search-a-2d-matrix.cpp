#include<vector>
class Solution {
//先按照行来查找插入的位置，如果插入位置为0，则表示不存在，否则从插入位置的前一行搜索。
//2019-11-12
public:
    bool searchMatrix(std::vector<std::vector<int> >& matrix, int target) {
        if(matrix.size() == 0 || matrix.size() == 1 || matrix[0].size() == 0){
            return false;
        }
        int row = findRow(matrix, target);
        if(row == 0){
            return false;
        }
        return findCol(matrix, row -1, target);
    }

    bool findCol(std::vector<std::vector<int> >& matrix, int row, int target){
        int low = 0;
        int high = matrix[0].size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(target > matrix[row][mid]){
                low = mid + 1;
            } else if (target < matrix[row][mid]){
                high = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    int findRow(std::vector<std::vector<int> >& matrix, int target){
        int low = 0;
        int high = matrix.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(target > matrix[mid][0]){
                low = mid + 1;
            } else if(target < matrix[mid][0]){
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return low;
    }
};