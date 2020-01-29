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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vec;
        // 辅助队列
        queue<TreeNode*> qu;
        if(!root){
            return vec;
        }
        TreeNode *work;
        qu.push(root);
        while(qu.size()){
            TreeNode *work = qu.front();
            qu.pop();
            vec.push_back(work->val);
            if(work->left){
                qu.push(work->left);
            }
            if(work->right){
                qu.push(work->right);
            }
        }

        return vec;
    }
};