#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<char> &str,int start,int end){
        for(int i = start,j = end;i < j;){
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }
    string LeftRotateString(string str, int n) {
        vector<char> vec(str.begin(),str.end());
        int len = str.length();
        if(len == 0){
            return "";
        }
        n %= len;
        rotate(vec,0,len - 1);
        rotate(vec,0,len - n - 1);
        rotate(vec,len - n,len - 1);
        string retStr(vec.begin(),vec.end());
        return retStr;
    }
};
int main(){
    string temp;
    int n;
    cin >> temp >> n;
    Solution so;
    cout << so.LeftRotateString(temp,n);
    return 0;
}