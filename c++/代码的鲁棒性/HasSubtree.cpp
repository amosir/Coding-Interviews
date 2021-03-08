#include<iostream>
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
private:
    bool match(TreeNode *root1,TreeNode *root2){
        // root2遍历完
        if(root2 == NULL){
            return true;
        }
        // root1遍历完，root2没遍历完
        if(root1 == NULL){
            return false;
        }
        // 值不相等
        if(root1->val != root2->val){
            return false;
        }
        // 左右子树
        return match(root1->left,root2->left) && 
            match(root1->right,root2->right);
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool flag = false;
        if(pRoot1 && pRoot2){
            flag = match(pRoot1,pRoot2);
            if(!flag){
                //根节点不匹配，则继续匹配左子节点
                flag = match(pRoot1->left,pRoot2);
            }
            if(!flag){
                //根节点不匹配，则继续匹配右子节点
                flag = match(pRoot1->right,pRoot2);
            }
        }
        return flag;
    }
};