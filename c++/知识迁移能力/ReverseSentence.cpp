#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    // 反转字符串
    void reverse(string &str,int left,int right){
        while(left < right){
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            left++;
            right--;
        }
    }

public:
    string ReverseSentence(string str) {
        int len = str.length();
        if(len == 0){
            return "";
        }
        // 反转整个句子
        reverse(str,0,len - 1);
        // 记录每个单词的起始和结束索引
        int left = 0,right = 0;
        for(int i = 0;i < len;i++){
            if(str[i] == ' '){
                // 反转每个单词
                reverse(str,left,right);
                left = i + 1;
            }else{
                right = i;
            }
        }
        // 反转最后一个单词
        reverse(str,left,len - 1);
        return str;
    }
};
int main(){
    string temp;
    getline(cin,temp);
    Solution so;
    cout << so.ReverseSentence(temp);
    return 0;
}