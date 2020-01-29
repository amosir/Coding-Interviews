#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int len  = numbers.size();
        if(len == 0){
            return 0;
        }

        // 记录次数最多的数的索引，初始时为第一个元素
        int targetIndex = 0;
        // 出现的次数，出现一次加1，不出现一次则减1
        int cnt = 1;
        for(int i = 1;i < len;i++){
            if(numbers[i] == numbers[targetIndex]){
                cnt++;
            }else{
                // 选定当前数的索引为目标索引
                if(cnt == 0){
                    targetIndex = i;
                    cnt = 1;
                }
                // 抵消一次
                else{
                    cnt--;
                }
            }
        }
        // 验证出现次数最多的数是否超过了一半
        cnt = 0;
        for(int i = 0;i < len;i++){
            if(numbers[targetIndex] == numbers[i]){
                cnt++;
            }
        }
        if(cnt * 2 > len){
            return numbers[targetIndex];
        }else{
            return 0;
        }
    }
};