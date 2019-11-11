#include<vector>
class Solution {
//2019-11-08
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int lastIdx = m + n -1;
       int i = m - 1;
       int j = n -1;
       while(i >= 0 && j >=0){
           if(nums1[i] <=nums2[j]){
               nums1[lastIdx--] = nums2[j--];
           } else{
               nums1[lastIdx--] = nums1[i--];
           }
       }
        //如果num1还有剩余已经是有序了，否则要用nums2来填充。
       while(j >=0){
           nums1[lastIdx--] = nums2[j--];
       }
        
    }
};