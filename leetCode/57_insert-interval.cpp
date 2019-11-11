#include<vector>
class Solution {
//2019-11-11
//同56题相同，先获取有序区间、然后找到插入位置，插入该interval
//然后遍历一遍进行区间的merge，时间复杂度为O(nlogn)
public:
    std::vector<std::vector<int> > insert(std::vector<std::vector<int> >& intervals, 
                                          std::vector<int>& newInterval) {    
 std::vector<std::vector<int> > result;                                
         if(intervals.size() == 0){
            result.push_back(newInterval);
            return result;
        }
        //找到newInterval需要插入的位置，然后使用O(n)的merge方法。
        int idx = findInsert(intervals, newInterval[0]);
        intervals.insert(intervals.begin() + idx, newInterval);
        std::vector<int> tmp = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= tmp[1]){
                tmp[1] = std::max(intervals[i][1], tmp[1]);
            } else{
                result.push_back(tmp);
                tmp = intervals[i]; 
            }
            
            if(i == intervals.size() -1){
                result.push_back(tmp);
            }
        }
        return result;
    }

    int findInsert(std::vector<std::vector<int> >& intervals, int target){
        int low = 0;
        int high = intervals.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(intervals[mid][0] < target){
                low = mid + 1;
            } else if(intervals[mid][0] > target){
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return low;
    }
};