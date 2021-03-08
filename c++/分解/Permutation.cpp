#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> vec;
        if(str.empty()){
            return vec;
        }
        // 访问标记
        for(int i = 0;i < 9;i++){
            visited[i] = false;
        }
        // 按字典排序
        sort(str.begin(),str.end());
        // 从第一个字符处开始填充
        generate(0,str);
        vec.assign(res_set.begin(),res_set.end());
        return vec;
    }
    void generate(int index,string str){
        // 到达边界则表示完成一次排列
        if(index == str.length()){
            res_set.insert(sequence);
            return;
        }
        // 否则如果当前字符没有访问过则访问当前字符并加入一个排列，然后继续填充
        // 后面的字符
        else{
            for(int j = 0;j < str.length();j++){
                if(visited[j] ==  false){
                    // 设置访问标记
                    visited[j] = true;
                    sequence.push_back(str[j]);
                    // 下一个位置
                    generate(index + 1,str);
                    // 还原
                    visited[j] = false;
                    sequence.pop_back();
                }
            }
        }
    }
private:
    bool visited[9];
    // 为了去重
    set<string> res_set;
    string sequence = "";
};

int main(){
    string s = "abc";
    Solution  so;
    vector<string> vec = so.Permutation(s);
    for(int i = 0;i < vec.size();i++){
        cout <<  vec[i] <<  endl;
    }
    return 0;
}