#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;
        // 输入数组长度
        int len = array.size();
        if(len < 2){
            return ret;
        }

        // 左指针指向第一个元素，右指针指向最右边元素
        int left = 0,right = len - 1;
        // 用于记录当前最小乘积
        int multi = array[len - 1] * array[len - 1];
        while(left < right){
            int temp_sum = array[left] + array[right];
            // 两数和等于目标数，如果乘积比之前最小乘积小则记录
            if(temp_sum == sum){
                int temp = array[left] * array[right];
                if(temp < multi){
                    ret.clear();
                    ret.push_back(array[left]);
                    ret.push_back(array[right]);
                    multi = temp;
                }
                left++;
                right--;
            }else if(temp_sum > sum){
                right--;
            }else{
                left++;
            }
        }
        return ret;
    }
};