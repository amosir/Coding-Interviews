#include<iostream>
#include<vector>
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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree){
            return pRootOfTree;
        }

        // 返回链表的头指针和尾指针
        TreeNode *retHead = NULL;
        TreeNode *retTail = NULL;
        // 辅助栈
        vector<TreeNode*> vec;
        TreeNode *work = pRootOfTree;
        while(work || vec.size()){
            // 到最左端节点
            if(work){
                vec.push_back(work);
                work = work->left;
            }else{
                work = vec.back();
                TreeNode *temp = work;
                vec.pop_back();
                work = work->right;
                if(retHead == NULL){
                    retHead = retTail = temp;
                }else{
                    retTail->right = temp;
                    temp->left = retTail;
                    retTail = retTail->right;
                }
            }
        }
        return retHead;
    }
};

int main(){
    Solution so;
    TreeNode *node1 = new TreeNode(8);
    TreeNode *node2 = new TreeNode(6);
    TreeNode *node3 = new TreeNode(10);
    TreeNode *node4 = new TreeNode(5);
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node6 = new TreeNode(9);
    TreeNode *node7 = new TreeNode(11);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    TreeNode *head = so.Convert(node1);
    return 0;
}