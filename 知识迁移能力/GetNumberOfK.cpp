#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len = data.size();
        if(len == 0){
            return 0;
        }
        // 第一个目标元素
        int start = 0,end = len - 1;
        for(int i = 0;i < len;i++){
            if(data[i] == k){
                start = i;
                break;
            }
        }
        // 最后一个目标元素
        for(int j = start;j < len;j++){
            if(data[j]!=k){
                end = j - 1;
                break;
            }
        }
        return end - start + 1;
    }
};
int main(){
    int cnt;
    cin >> cnt;
    int num;
    cin >> num;
    vector<int> vec;
    for(int i = 0;i < cnt;i++){
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    Solution so;
    cout << so.GetNumberOfK(vec,num);
    return 0;
}