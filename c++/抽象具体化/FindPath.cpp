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
//非递归后续遍历方式
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        // 用于返回
        vector<vector<int> > retVec;
        if(!root){
            return retVec;
        }
        // 辅助栈
        vector<TreeNode*> tempVec;
        // 保存一条路径
        vector<int> aPathVec;
        // 临时路径和
        int tempPathSum = 0;
        TreeNode *work = root;
        // 记录上一次访问的节点
        TreeNode *lastVisited = NULL;
        while(work || tempVec.size() > 0){
            if(work){
                // 增加路径和并将当前节点值添加到一条路径中
                tempPathSum += work->val;
                aPathVec.push_back(work->val);
                tempVec.push_back(work);
                // 满足路径和的叶子节点，一条路径完毕，添加到结果中
                if(tempPathSum == expectNumber && !work->left && !work->right){
                    retVec.push_back(aPathVec);
                }
                work = work->left;
            }else{
                work = tempVec.back();
                // 右节点存在且未访问过
                if(work->right && lastVisited!=work->right){
                    work = work->right;
                }
                // 如果右节点不存在或访问过
                else{
                    tempVec.pop_back();
                    aPathVec.pop_back();
                    tempPathSum -= work->val;
                    lastVisited = work;
                    work = NULL;
                }
            }
        }
        return retVec;
    }
};