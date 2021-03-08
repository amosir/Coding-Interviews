#include<iostream>
using namespace std;
class Solution {
public:
    /**
    * 
    * 1. 如果第i位（自右至左，从1开始标号）上的数字为0，则第i位可能出现1的次数由更高位决定（若没有高位，视高位为0），等于更高位数字X当前位数的权重10i-1。

    * 2. 如果第i位上的数字为1，则第i位上可能出现1的次数不仅受更高位影响，还受低位影响（若没有低位，视低位为0），等于更高位数字X当前位数的权重10i-1+（低位数字+1）。

    * 3. 如果第i位上的数字大于1，则第i位上可能出现1的次数仅由更高位决定（若没有高位，视高位为0），等于（更高位数字+1）X当前位数的权重10i-1。
    */
    int NumberOf1Between1AndN_Solution(int n)
    {
        // 1的个数
        int count = 0;
        //当前位之前的数，当前位的数，当前位之后的数
        int  before = 0,current = 0,after = 0;
        // 当前位从个位开始
        int i = 1;
        while((n / i)!=0){
            before = n / (i * 10);
            current = (n / i) % 10;
            after = n - (n / i) * i;
            if(current == 0){
                count += before * i;
            }else if(current == 1){
                count += before * i + after + 1;
            }else {
                count += (before + 1) * i;
            }
            i = i * 10;
        }
        return count;
    }
};
int main(){
    int temp;
    cin >> temp;
    Solution so;
    cout << so.NumberOf1Between1AndN_Solution(temp);
    return 0;
}