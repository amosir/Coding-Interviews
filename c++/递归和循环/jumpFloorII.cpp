#include<iostream>
#include<vector>
using namespace std;
/**
 *  要想跳到第n级台阶，就可以从第n-1级、第n-2级、***、第1级 跳到第n级，再加上直接从地面到第n级的一种情况。
 * F(n-1) = F(n-2) + F(n-3) + ......+ F(1) + F(0); 
 * F(n) = F(n-1) + F(n-2) + ......+ F(1) + F(0);
 * F(n) = 2 * F(n-1)
 */
class Solution {
public:
    int jumpFloorII(int number) {
        if(number < 3){
            return number;
        }
        vector<int> vec(number + 1);
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 2;
        for(int i = 3;i <= number;i++){
            vec[i] = 2 * vec[i - 1];
        }
        return  vec[number];
    }
};