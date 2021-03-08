#include <iostream>
#include <vector>
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        // 边界检查
        if(!pRoot || k <= 0)
            return NULL;
        // 二叉搜索树中序序列是有序的
        vector<TreeNode*> inOrder; 
        // 辅助栈
        vector<TreeNode*> vec;

        TreeNode *work = pRoot;
        while(vec.size() > 0 || work){
            if(work){
                vec.push_back(work);
                work = work->left;

            }else{
                work = vec.back();
                vec.pop_back();
                inOrder.push_back(work);
                work = work->right;
            }
        }

        // 中序序列的第k个元素
        if(inOrder.size() >= k){
            return inOrder[k - 1];
        }
        return NULL;
    }
};