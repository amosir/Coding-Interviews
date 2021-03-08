#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int len =  sequence.size();
        if(len == 0){
            return false;
        }
        if(len == 1){
            return true;
        }
        return judge(sequence,0,len - 1);
    }

    // 序列的起点和终点
    bool judge(vector<int> sequence,int start,int end) {
        if(start >= end){
            return true;
        }
        // 后续序列的根节点在序列最后
        int root = sequence[end];
        // 寻找左子树序列，i最终指向右子树序列的第一个节点
        int i = 0;
        for(;i < end && sequence[i] < root;i++){}
        //  如果右子树中出现了比根节点小的元素则不构成二叉树
        for(int j = i;j < end;j++){
            if(sequence[j] < root){
                return false;
            }
        }
        return  judge(sequence,start,i - 1) && 
            judge(sequence,i,end - 1);
    }
};