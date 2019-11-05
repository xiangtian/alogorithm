#include<vector>
class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
       if(nums1.size() > nums2.size()){
           return findMedian(nums2, nums1);
       } 
       return findMedian(nums1, nums2);
    }

    double findMedian(std::vector<int>& first, std::vector<int>& second){
        int m = first.size();
        int n = second.size();
        int iMin = 0, iMax = m,halfLen = (m + n + 1) / 2;
        while(iMin <=iMax){
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if(i < iMax && second[j-1] > first[i]){
                iMin = i + 1;
            } else if(i > iMin && first[i-1] > second[j]){
                iMax = i-1;
            } else {
                int maxLeft = 0;
                if(i==0){
                    maxLeft = second[j-1];
                } else if(j == 0){
                    maxLeft = first[i-1];
                } else {
                    maxLeft = std::max(first[i-1], second[j-1]);
                }
                if((m + n ) % 2 == 1){
                    return maxLeft;
                }

                int minRight = 0;
                if(i == m){
                    minRight = second[j];
                } else if(j == n){
                    minRight = first[i];
                } else {
                    minRight = std::min(first[i], second[j]);
                }
                return (maxLeft + minRight) / 2;
            }
        }
        return 0.0;
    }
};