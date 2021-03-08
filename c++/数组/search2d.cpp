#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        // 多少行
        int xLen = array.size();
        if(xLen <= 0){
            return false;
        }
        // 多少列
        int yLen = array[0].size();
        if(yLen <= 0){
            return false;
        }

        bool flag = false;

        for(int i = 0;i < xLen;i++){
            // 在当前行查找
            if(array[i].at(0) <= target && target <= array[i].at(yLen - 1)){
                // 找到
                if(binary_search(array[i].begin(),array[i].end(),target)){
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
};