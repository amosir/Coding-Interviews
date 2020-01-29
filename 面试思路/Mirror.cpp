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
public:
    void Mirror(TreeNode *pRoot) {
        if(!pRoot){
            return;
        }
        this->Mirror(pRoot->left);
        this->Mirror(pRoot->right);
        TreeNode *temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right =  temp;
    }
};