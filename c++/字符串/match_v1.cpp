#include <iostream>
#include <string>
using namespace std;
/**
 * 递归回朔法:
 * 1. 没有*的情况: str[i] == pattern[i] || pattern[i] == '.'
 * 2. *在pattern中出现0次:保持str不变，pattern剪去前两个字符，然后继续递归
 * 3. *在pattern中出现1次或多次:比较首字符，首字符相等则剪去str的首字符,pattern不变，然后进行递归
 */
class Solution
{
private:
    bool match(string s, string p)
    {
        // 模式串p为空则根据s判断
        if (p.empty())
        {
            return s.empty();
        }
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

        // 如果下一个字符是*
        if (p.size() >= 2 && p[1] == '*')
        {
            return match(s, p.substr(2)) || (firstMatch && match(s.substr(1), p));
        }
        // 一般情况
        return firstMatch && match(s.substr(1), p.substr(1));
    }

public:
    bool match(char *str, char *pattern)
    {
        string s(str);
        string p(pattern);
        return match(s, p);
    }
};