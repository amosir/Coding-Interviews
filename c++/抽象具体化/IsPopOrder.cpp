#include<iostream>
#include<vector>
using namespace std;
/**
 * 设计一个辅助栈和一个指针，指针默认指向序列第一个元素，先入栈，每次入栈
 * 后判断栈顶是否与序列的第一个元素相等，不相等继续入栈，相
 * 等时弹出栈顶，指针后移一位，然后继续判断此时栈顶是否与指
 * 针指向的值相等，如果相等继续弹出栈顶，一直比较到栈为空，进
 * 行下一轮入栈或者是循环结束，最后如果辅助栈为空，说明该序列
 * 可能是该压栈序列的弹出序列。
 */
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 辅助栈
        vector<int> vec;
        int lenPushV = pushV.size();
        int lenPopV = popV.size();
        if(lenPushV == 0 || lenPopV == 0 || lenPopV!=lenPopV){
            return false;
        }

        // 从弹出序列的第一个元素开始
        int popIndex = 0;
        for(int i = 0;i < lenPopV;i++){
            vec.push_back(pushV[i]);
            while(vec.size()!=0 && vec.back() == popV[popIndex]){
                vec.pop_back();
                popIndex++;
            }
        }
        return vec.empty();
    }
};