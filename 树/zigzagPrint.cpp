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
    vector<vector<int> > Print(TreeNode* pRoot) {
        // 最终结果
        vector<vector<int> > result;
        // 每一行
        vector<int> row;

        if(pRoot == NULL){
            return result;
        }
        // 奇数层辅助栈
        vector<TreeNode*> oddLayervector;
        // 偶数层辅助栈
        vector<TreeNode*> evenLayervector;

        TreeNode *work = pRoot;
        oddLayervector.push_back(work);
        // 只要有一个不为空
        while(!oddLayervector.empty() || !evenLayervector.empty()){
            // 当前为偶数层
            while(!evenLayervector.empty()){
                work = evenLayervector.back();
                row.push_back(work->val);
                evenLayervector.pop_back();
                if(work->right){
                    oddLayervector.push_back(work->right);
                }
                if(work->left){
                    oddLayervector.push_back(work->left);
                }
            }
            if(row.size()){
                result.push_back(row);
                row.clear();
            }
            // 当前层是奇数层
            while(!oddLayervector.empty()){
                work = oddLayervector.back();
                row.push_back(work->val);
                oddLayervector.pop_back();
                if(work->left){
                    evenLayervector.push_back(work->left);
                }
                if(work->right){
                    evenLayervector.push_back(work->right);
                }
            }
            if(row.size()){
                result.push_back(row);
                row.clear();
            }
        }
        return result;
    }
    
};

int main(){
    Solution s0;
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
    vector<vector<int> > vec = s0.Print(node1);
    for(int i = 0;i < vec.size();i++){
        for(int j = 0;j < vec[i].size();j++){
            cout << vec[i].at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}