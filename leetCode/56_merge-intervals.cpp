#include<vector>
#include<queue>
#include<iostream>
class Solution {
public:
    std::vector<std::vector<int> > merge(std::vector<std::vector<int> >& intervals) {
        if(intervals.size() == 0 || intervals.size() == 1){
            return intervals;
        }

        std::vector<std::vector<int> > result;
        //按照interval[i][0]进行排序，排完序之后进行merge
        quickSort(intervals, 0, intervals.size() -1); 
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

    void quickSort(std::vector<std::vector<int> > &intervals, int left, int right){
        if(left >= right){
            return;
        }
        std::vector<int> base = intervals[left];
        int i = left;
        int j = right;
        while(i < j){
            while(i < j && intervals[j][0] >= base[0]){
                j--;
            }
            if(i < j){//需要进行有效性判断
                intervals[i++] = intervals[j];
            }
            while(i < j && intervals[i][0] < base[0]){
                i++;
            } 
            if(i < j){//需要进行有效性判断
                 intervals[j--] = intervals[i];
            }
        }
        intervals[i] = base;
        quickSort(intervals, left, i-1);
        quickSort(intervals, i+1, right);
    }
};