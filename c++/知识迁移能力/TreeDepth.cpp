#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(!pRoot){
            return 0;
        }
        // 深度
        int depth = 1;
        // 用于判断一层是否遍历完
        int count = 0;
        // 辅助队列
        queue<TreeNode*> qu;
        TreeNode *work = pRoot;
        qu.push(work);
        while(qu.size() > 0){
            work = qu.front();
            qu.pop();
            count--;
            if(work->left){
                qu.push(work->left);
            }
            if(work->right){
                qu.push(work->right);
            }
            // 一层遍历完则深度加1
            if(count == 0){
                depth++;
                count = qu.size();
            }
        }
        return depth;
    }
};