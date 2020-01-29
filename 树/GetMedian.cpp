#include <iostream>
#include<functional>
#include <queue>
using namespace std;
/***
    对于一个升序排序的数组，中位数为左半部分的最大值，右半部分的最小值，而左右两部分可以是无需的，只要保证左半部分的数均小于
    右半部分即可。因此，左右两半部分分别可用最大堆、最小堆实现。
    首先定义：如果有奇数个数，则中位数放在左半部分；如果有偶数个数，则取左半部分的最大值、右边部分的最小值之平均值
    分两种情况讨论：
    当目前有偶数个数字时，数字先插入最大堆，然后选择最大堆的最大值插入最小堆（第一个数字插入左半部分的最小堆）
    当目前有奇数个数字时，数字先插入最小堆，然后选择最小堆的最小值插入最大堆
    如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
    ***/
class Solution {
public:
    void Insert(int num)
    {
        cnt++;
        // 当前有偶数个值，先插入到左边大顶堆，再将左边大顶堆的最大值插入右边小顶堆
        if(cnt % 2 == 0){
            leftMaxHeap.push(num);
            int max = leftMaxHeap.top();
            leftMaxHeap.pop();
            rightMinHeap.push(max);
        }
        // 当前有奇数个值，先插入到右边小顶堆，再将右边小顶堆堆的最小值插入左边大顶堆
        else{
            rightMinHeap.push(num);
            int min = rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(min);
        }
    }

    double GetMedian()
    {
        // 偶数个
        if((cnt & 1) == 0){
            return (leftMaxHeap.top() + rightMinHeap.top()) / 2.0;
        }
        // 奇数个
        else{
            return leftMaxHeap.top();
        }
        
    }

private:
    // 左边的大顶堆
    priority_queue<int,vector<int>,less<int> > leftMaxHeap;
    // 右边的小顶堆
    priority_queue<int,vector<int>,greater<int> > rightMinHeap;
    // 总数
    int cnt;
};