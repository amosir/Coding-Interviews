#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size() <= 0 || vin.size() <= 0){
            return NULL;
        }
        return reConstructBinaryTree(pre,0,pre.size() - 1,vin,0,vin.size() - 1);
    }

    // rootIndex 是根节点在前序中的索引
    TreeNode* reConstructBinaryTree(vector<int> pre,int preStart,int preEnd,vector<int> vin,int inStart,int inEnd) {
        if(preStart <= preEnd && inStart <= inEnd){
            TreeNode *root = new TreeNode(pre[preStart]);
            // 根节点在中序序列中的索引
            int rootInVin;
            for(rootInVin = inStart;vin[rootInVin] != pre[preStart];rootInVin++){
            }

            root->left = reConstructBinaryTree(pre,preStart + 1,
                    preStart + rootInVin - inStart,vin,inStart,rootInVin - 1);

            root->right = reConstructBinaryTree(pre,preEnd - (inEnd - rootInVin) + 1,
                    preEnd,vin,rootInVin + 1,inEnd);
            
            return root;
        }
        return NULL;
    }
};

int main(){
    int pre[] = {1,2,4,7,3,5,6,8};
    int in[] = {4,7,2,1,5,3,8,6};
    vector<int> preV(pre,pre + 8);
    vector<int> inV(in,in + 8);
    Solution so;
    so.reConstructBinaryTree(preV,inV);
    return 0;
}