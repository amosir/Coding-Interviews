#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > ret;
        if(sum <= 2){
            return ret;
        }
        int mid = (1 + sum) >> 1;
        int left = 1,right = 2,temp_sum = 3;
        while(left < mid && right < mid + 1){
            while(temp_sum > sum){
                temp_sum -= left;
                left++;
            }
            if(temp_sum == sum){
                vector<int> vec;
                for(int i = left;i <= right;i++){
                    vec.push_back(i);
                }
                ret.push_back(vec);
            }
            ++right;
            temp_sum += right;
        }
        return ret;
    }
};
int main(){
    Solution so;
    int temp;
    cin >> temp;
    vector<vector<int> > vec = so.FindContinuousSequence(temp);
    return 0;
}