#include<vector>
class Solution {
//2019-11-14
public:
    void reverseString(std::vector<char>& s) {
        int left = 0;
        int right = s.size() -1;
        while(left < right){
            char tmp = s[right];
            s[right] = s[left];
            s[left] = tmp;
            left++;
            right--;
        }   
    }
};