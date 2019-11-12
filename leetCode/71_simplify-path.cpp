#include<string>
#include<list>
class Solution {
//2019-11-12
//依次遍历字符串、
//遇到非”/"时组合字符串，将字符串组合后如果不为"." ".."则放入栈中
//遇到".."如果栈不空，则弹出栈，否则什么都不做
//遇到"." 则什么都不做直接忽略
//注意：最后可能以非“/”方式结尾
public:
    std::string simplifyPath(std::string path) {
        std::string result;
        std::list<std::string> s;
        std::string dir;
        for(int i = 0; i < path.length(); i++){
            if(path[i] =='/'){
                processDir(s, dir);
                continue;
            }
            dir.push_back(path[i]);  
        }
        processDir(s, dir);//最后以非“/”结尾
        
        if(s.empty()){
            result += "/";
        } else {
            while(!s.empty()){
                result += "/";
                result += (s.front());
                s.pop_front();
            }
        }
        return result; 
    }
    
    void processDir(std::list<std::string>& s, std::string& dir){
    //处理遇到的字符串
        if(dir != ""){
            if(dir != "." && dir != ".."){
                s.push_back(dir);
            } else if (dir == ".."){
                if(s.size() > 0){
                    s.pop_back();
                }
            }
            dir = "";
        }
    }
};