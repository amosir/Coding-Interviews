#include<iostream>
using namespace std;
class Solution {
public:
     int  NumberOf1(int n) {
         unsigned int temp = (unsigned)n;
         int cnt = 0;
         while(temp!=0){
            if((temp & 1) == 1){
                cnt++;
            }
            temp = temp >> 1;
         }
         return cnt;
     }
};

int main(){
    Solution so;
    int temp;
    cin >> temp;
    cout << so.NumberOf1(temp);
}