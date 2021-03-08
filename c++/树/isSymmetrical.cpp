#include <iostream>
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
    bool isSymmetrical(TreeNode *node1,TreeNode *node2){
        // 对称位置两个节点为空
        if(node1 == NULL && node2 == NULL){
            return true;
        }
        // 对称位置只有一个为空
        else if(!node1 || !node2){
            return false;
        }
        // 对称位置都不为空，需要值相等且子节点对应位置也对称
        else{
            return node1->val == node2->val && isSymmetrical(node1->left,node2->right) 
               && isSymmetrical(node1->right,node2->left);
        }
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return true;
        return isSymmetrical(pRoot->left,pRoot->right);
    }
};