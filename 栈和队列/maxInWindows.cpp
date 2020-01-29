#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> maxInWindows(const vector<int> &num, unsigned int size)
    {
        // 保存最终结果
        vector<int> result;
        // 窗口，前面的元素一定大于后面的元素，这样前面的元素就是最大值
        deque<int> window;
        int len = num.size();
        if (size == 0 || len == 0 || len < size)
        {
            return result;
        }
        // 第一个窗口
        for (int i = 0; i < size; i++)
        {
            // 如果当前遍历元素比窗口尾部的元素大，那么尾部的元素必然不是
            // 最大值，出队
            while (!window.empty() && num[i] > num[window.back()])
            {
                window.pop_back();
            }
            // 当前元素比尾部元素小，尾部元素出队后依然可能成为最大值，入队
            window.push_back(i);
        }

        result.push_back(num[window.front()]);

        for (int i = size; i < len; i++)
        {
            while (!window.empty() && num[i] > num[window.back()])
            {
                window.pop_back();
            }
            window.push_back(i);
            // 队头元素已滑出窗口，出队
            if (!window.empty() && window.front() <= i - size)
            {
                window.pop_front();
            }
            result.push_back(num[window.front()]);
        }
        return result;
    }
};

int main()
{
    int cnt;
    cin >> cnt;
    vector<int> vec;
    for (int i = 0; i < cnt; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    Solution so;
    vector<int> v = so.maxInWindows(vec, 3);
    for (int j = 0; j < v.size(); j++)
    {
        cout << v[j] << " ";
    }
    return 0;
}