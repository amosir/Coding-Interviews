#include<iostream>
using namespace std;
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == NULL) return false;
        // 符号、E、.是否出现过
        bool flag = false,hasE = false,hasDot = false;
        for(int i = 0;string[i]!='\0';i++){
            if(string[i] == 'E' || string[i] == 'e'){
                // e只能出现一次且不在最后一位
                if(hasE || string[i+1] == '\0'){
                    return false;
                }
                hasE = true;
            }else if(string[i] == '.'){
                // .只能出现一次且不能出现在最后一位
                if(hasE || hasDot || string[i + 1] == '\0'){
                    return false;
                }
                hasDot = true;
            }else if(string[i] == '+' || string[i] == '-'){
                // 第一次出现只能在第一位或出现在E后面且不能出现在E后面
                if(!flag && i != 0 && string[i - 1] != 'e' && 
                    string[i - 1] != 'E'){
                        return false;
                    }
                // 第二次出现出现在E后面
                if(flag && string[i - 1]!='e' && string[i-1]!='E'){
                    return false;
                }
                flag = true;
            }else if(string[i] < '0' || string[i] > '9'){
                return false;
            }
        }
    return true;
    }
};
int main(){
    Solution so;
    int cnt;
    cin >> cnt;
    char *string = new char(cnt + 1);
    for(int i = 0;i < cnt;i++){
        char ch;
        cin >>ch;
        string[i] = ch;
    }
    string[cnt] = '\0';
    cout << so.isNumeric(string);
    return 0;
}