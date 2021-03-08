#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> char_map;
        int len = str.length();
        for(int i = 0;i < len;i++){
            map<char,int>::iterator it = char_map.find(str[i]);
            if(it == char_map.end()){
                char_map.insert(pair<char,int>(str[i],1));
            }else{
                (it->second)++;
            }
        }
        for(int i = 0;i < len;i++){
            map<char,int>::iterator it  = char_map.find(str[i]);
            if(it->second == 1){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    string str =  "google";
    Solution so;
    cout << so.FirstNotRepeatingChar(str);
    return  0;
}