#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
private:
    static bool compare(int x,int y){
        string x_str = to_string(x);
        string y_str = to_string(y);
        return x_str + y_str < y_str + x_str;
    }
public:
    string PrintMinNumber(vector<int> numbers) {
        int len = numbers.size();
        if(len < 1){
            return "";
        }
        string retStr = "";
        sort(numbers.begin(),numbers.end(),Solution::compare);
        for(int i = 0;i < len;i++){
            retStr += to_string(numbers[i]);
        }
        return retStr;
    }
};
int main(){
    vector<int> vec;
    int cnt;
    cin >> cnt;
    while(cnt > 0){
        int temp;
        cin >> temp;
        vec.push_back(temp);
        cnt--;
    }
    Solution so;
    cout << so.PrintMinNumber(vec);
    return 0;
}