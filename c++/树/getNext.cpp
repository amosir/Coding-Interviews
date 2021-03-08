/**
 *  1. 如果节点有右子节点，则右子节点的最左节点是该节点的下一个节点
 *  2. 如果节点无右子节点，但该节点是父节点的左子节点，则父节点是该节点的下一个节点。
 *  3. 如果节点无右子节点，且该节点是父节点的右子节点，则沿着父节点的指针向上遍历
 */
#include<iostream>
using namespace std;
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 当前节点为空
        if(pNode == NULL){
            return NULL;
        }
        // 右子节点存在
        if(pNode->right!=NULL){
            TreeLinkNode *work = pNode->right;
            while(work->left){
                work = work->left;
            }
            return work;
        }
        // 右子节点不存在,向上回溯到第一个存在左节点的节点
        TreeLinkNode *work = pNode;
        TreeLinkNode *workParent = pNode->next;
        while(workParent!=NULL && workParent->right == work){
            work = workParent;
            workParent = work->next;
        }
        return workParent;     
    }
};

int main(){
    return 0;
}