#include<iostream>
#include<vector>
using namespace std;
/**
 * 从前向后依次异或数组中的数字，那么得到的结果是两个只
 * 出现一次的数字的异或结果，其他成对出现的数字被抵消了。
 * 由于这两个数字不同，所以异或结果肯定不为0，也就是这个
 * 异或结果一定至少有一位是1，我们在结果中找到第一个为1
 * 的位的位置，记为第n位。接下来，以第n位是不是1为标准，
 * 将数组分为两个子数组，第一个数组中第n位都是1，第二个数
 * 组中第n位都是0。这样，便实现了我们的目标。最后，两个子数
 * 组分别异或则可以找到只出现一次的数字。
 */
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int temp = 0;
        int len = data.size();
        for(int i = 0;i < len;i++){
            temp ^= data[i];
        }

        // 寻找第一个1所在的索引
        int j;
        for(j = 0;j < 32;j++){
            if(((temp >> j) & 1) == 1){
                break;
            }
        }

        int temp_1 = 0;
        int temp_0 = 0;
        // 第j位为1的和为0的所有数字分开
        for(int k = 0;k < len;k++){
            if(((data[k] >> j) & 1) == 1){
                temp_0 ^= data[k];
            }else{
                temp_1 ^= data[k];
            }
        }
        *num1 = temp_0;
        *num2 = temp_1;
        return;
    }
};