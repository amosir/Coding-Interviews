#include<iostream>
#include<algorithm>
#include<math.h>
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot){
            return true;
        }
        int leftHeight = getHeight(pRoot->left);
        int rightHeight = getHeight(pRoot->right);
        return abs(leftHeight - rightHeight) <= 1 &&  
            IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    int getHeight(TreeNode *root){
        if(!root){
            return 0;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return max(leftHeight,rightHeight) + 1;
    }
};