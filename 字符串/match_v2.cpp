#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
private:
    bool first_match(string s, int i, string p, int j)
    {
        return (s[i] == p[j] || p[j] == '.');
    }

public:
    bool match(char *str, char *pattern)
    {
        string s(str);
        string p(pattern);

        int len_s = s.length();
        int len_p = p.length();
        // dp[i][j] 表示s的前i个字符是否和p的前j个字符匹配
        bool dp[len_s + 1][len_p + 1];
        for (int i = 0; i <= len_s; i++)
        {
            for (int j = 0; j <= len_p; j++)
            {
                dp[i][j] = false;
            }
        }
        // 匹配串和模式串都是空串的情况
        dp[0][0] = true;

        for (int i = 0; i < len_s; i++)
        {
            for (int j = 0; j < len_p; j++)
            {
                // 模式串当前元素为*,有两种情况:
                // 1, *前面的字符出现0次，则dp[i + 1][j + 1] = dp[i + 1][j - 1]
                // 2. *前面的字符出现1次或多次，比较当前字符是否匹配和dp[i][j + 1](即主串去掉当前
                // 元素后是否与模式串匹配)
                if (p[j] == '*')
                {
                    dp[i + 1][j + 1] = dp[i + 1][j - 1] ||
                                       (first_match(s, i, p, j - 1) && dp[i][j + 1]);
                }
                // 没有*则比较当前元素是否匹配和当前位置之前的元素是否匹配
                else
                {
                    dp[i + 1][j + 1] = first_match(s, i, p, j) && dp[i][j];
                }
            }
        }
        return dp[len_s][len_p];
    }
};