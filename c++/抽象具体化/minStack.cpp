#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void push(int value) {
        vec1.push_back(value);
        // 栈空
        if(s_top == -1){
            s_top++;
            vec2.push_back(value);
            return;
        }
        // 栈不空
         s_top++;
        int top_min = vec2.back();
        if(top_min < value){
            vec2.push_back(top_min);
        }else{
            vec2.push_back(value);
        }
    }
    void pop() {
        if(s_top!=-1){
            vec1.pop_back();
            vec2.pop_back();
            s_top--;
        }
    }
    int top() {
        if(s_top!=-1){
            return vec1.back();
        }
        return 0;
    }
    int min() {
        if(s_top!=-1){
            return vec2.back();
        }
        return 0;
    }
private:
    // 存放实际的入栈元素
    vector<int> vec1;
    // 存放当前的最小元素
    vector<int> vec2;
    // 栈顶
    int s_top = -1;
};