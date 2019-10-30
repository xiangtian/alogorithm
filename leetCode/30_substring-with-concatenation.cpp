//LeetCode: 30
//2019-10-25
#include<vector>
#include<string>
#include<unordered_map>
class Solution {
//使用map来记录是否在map中，如果map为空、就记录起始位置
//使用map来分辨words中的重复元素
//相比之前通过的算法，这种方法没有使用erase、只是查找并比较大小、性能一下子提高了很多
//内存消耗也好了很多
//2019-10-25
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        //words为空
        if (words.size() == 0){
            return result;
        }
        //总长度大于s
        int wordLength = words[0].length();
        int wordNum = words.size();
        if (wordLength * words.size() > s.length()){
            return result;
        }

        std::unordered_map<std::string, int> wordCount;
        for (int i = 0; i < words.size(); i++){
            if (wordCount.find(words[i]) != wordCount.end()){
                wordCount[words[i]]++;
            }else{
                wordCount[words[i]] = 1;
            }
        }

        int maxIdx = s.length() - wordLength * words.size() + 1;//i的最大位置。
        for (int i = 0; i < maxIdx; i++){
            std::unordered_map<std::string, int> hasWords;
            int num = 0;
            while (num < wordNum){
                std::string word = s.substr(i + num * wordLength, wordLength);
                if (wordCount.find(word) != wordCount.end()){//使用查找而不是删除
                    if (hasWords.find(word) != hasWords.end()){
                        hasWords[word]++;
                    }else{
                        hasWords[word] = 1;
                    }
                    if (hasWords[word] > wordCount[word]){
                        break;
                    }
                }else{
                    break;
                }
                num++;
            }
            if (num == wordNum){
                result.push_back(i);
            }
        }
        return result;
    }
};