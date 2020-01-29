#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> nums;
        if(n < 0){
            return -1;
        }
        if(n == 0){
            return 0;
        }
        if(n == 1 || n == 2){
            return 1;
        }
        nums.push_back(0);
        nums.push_back(1);
        nums.push_back(1);
        for(int i = 3;i <= n;i++){
            nums.push_back(nums[i - 1] + nums[i - 2]);
        }
        return nums[n];
    }
};