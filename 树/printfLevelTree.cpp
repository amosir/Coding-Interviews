#include <vector>
#include <queue>
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
            // 存放最终的结果
            vector<vector<int> > ret;

            // 暂存每一行
            vector<int> tempVec;

            TreeNode *work = pRoot;

            // 空树直接返回
            if(pRoot == NULL)
                return ret;
            
            // 辅助队列
            queue<TreeNode*> qu;
            qu.push(pRoot);
            int count = 1;
            while(qu.size() > 0){
                work = qu.front();
                tempVec.push_back(work->val);
                qu.pop();
                count --;
                if(work->left){
                    qu.push(work->left);
                }
                if(work->right){
                    qu.push(work->right);
                }
                // 某一行全部出队，将该行添加到最终结果中
                if(count == 0){
                    ret.push_back(tempVec);
                    count = qu.size();
                    tempVec.clear();
                }
            }
            return ret;
        }
    
};