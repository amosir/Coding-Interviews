#include<iostream>
#include<limits>
using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        // 数字和符号
        long long num = 0,flag = 1;
        int len = str.length();
        if(len == 0){
            return 0;
        }
        for(int i = 0;i < len;i++){
            // 负数
            if(i == 0 && str[i] == '-'){
                flag = -1;
                continue;
            }
            if(i == 0 && str[i] == '+'){
                flag = 1;
                continue;
            }
            if(str[i] - '0' < 0 || str[i] - '0' > 9){
                return 0;
            }else{
                num = (num << 3) + (num << 1) + (str[i] - '0' + 0);
            }
        }
        long long ret = num * flag;
        if(ret > INT_MAX || ret < INT_MIN){
            return 0;
        }else{
            return ret;
        }
    }
};
int main(){
    string temp;
    cin >> temp;
    Solution so;
    cout << so.StrToInt(temp);
    return 0;
}