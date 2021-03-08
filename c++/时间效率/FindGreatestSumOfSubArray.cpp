#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int len = array.size();
        if(len == 0){
            return 0;
        }
        // 动态规划辅助数组
        vector<int> dp;
        for(int i = 0;i < len;i++){
            if(i == 0){
                dp.push_back(array[0]);
            }else{
                int temp = dp[i - 1] + array[i];
                if(temp > array[i]){
                    dp.push_back(temp);
                }else{
                    dp.push_back(array[i]);
                }
            }
        }
        int max = 0;
        for(int i = 1;i < len;i++){
            if(dp[i] > dp[max]){
                max = i;
            }
        }
        return dp[max];
    }
};
int main(){
    vector<int> vec;
    vec.push_back(6);
    vec.push_back(-3);
    vec.push_back(-2);
    vec.push_back(7);
    vec.push_back(-15);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(2);
    Solution so;
    cout << so.FindGreatestSumOfSubArray(vec);
    return 0;
}
