#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * 首先应该对数组进行排序。
 * 统计数组中大小王（0）出现的个数。
 * 统计数组中所有相邻数之间的间隔。
 * 同时还需要排除对子的情况，如果出现了对子，那么肯定不可能是顺子（0除外）。
 * 最后比较0的个数和间隔大小，如果0的个数大于等于间隔数，说明可以组成顺
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5){
            return false;
        }
        sort(numbers.begin(),numbers.end());

        // count0记录0的个数，gap记录差距
        int count0 = 0,len = numbers.size(),gap = 0;
        for(int i = 0;i < len - 1;i++){
            if(numbers[i] == 0){
                count0++;
                continue;
            }
            // 处理对子
            if(numbers[i] == numbers[i+1]){
                return false;
            }

            // 相邻两个数的差距
            gap += numbers[i + 1] - numbers[i] - 1;

        }
        if(count0 >= gap){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution so;
    vector<int> ret;
    for(int i = 0;i < 5;i++){
        int temp;
        cin >> temp;
        ret.push_back(temp);
    }
    cout << so.IsContinuous(ret);
    return 0;
}