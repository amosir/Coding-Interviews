#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};
class Solution
{
public:
    void SerializeCore(TreeNode *root)
    {
        if (root == NULL)
        {
            stream.push_back('#');
            stream.push_back('!');
            return;
        }
        stream += to_string(root->val);
        stream.push_back('!');
        SerializeCore(root->left);
        SerializeCore(root->right);
    }
    char *Serialize(TreeNode *root)
    {
        if (!root)
        {
            return NULL;
        }
        SerializeCore(root);
        int len = stream.length();
        char *ret = new char(len + 1);
        for (int i = 0; i < len; i++)
        {
            ret[i] = stream[i];
        }
        ret[len] = '\0';
        return ret;
    };

    // 分割字符串
    void split_string(string str, char token)
    {
        string temp = "";
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            if (str[i] != token)
            {
                temp.push_back(str[i]);
            }
            else
            {
                vec.push_back(temp);
                temp = "";
            }
        }
    };

    TreeNode *Deserialize(char *str)
    {
        if (str == NULL)
        {
            return NULL;
        }
        return DeserializeCore(str);
    };

    TreeNode *DeserializeCore(char *str)
    {
        string s(str);
        split_string(s, '!');
        if (pos < vec.size())
        {
            if (vec[pos] == "#")
            {
                pos++;
                return NULL;
            }
            else
            {
                TreeNode *root = new TreeNode(stoi(vec[pos]));
                pos++;
                root->left = DeserializeCore(str);
                root->right = DeserializeCore(str);
                return root;
            }
        }
        else
        {
            return NULL;
        }
    }

private:
    string stream;
    vector<string> vec;
    int pos = 0;
};

int main()
{
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
    char *s = s0.Serialize(node1);
    TreeNode *root = s0.Deserialize(s);
    return 0;
}