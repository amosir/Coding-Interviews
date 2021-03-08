#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minimum(int a,int b,int c){
        int temp = a < b ? a : b;
        return temp < c ? temp : c;
    }
    int GetUglyNumber_Solution(int index) {
        if(index <= 6){
            return index;
        }
        vector<int> tempVec;
        tempVec.push_back(1);
        int min_num = 1;
        int times2 = 0,times3 = 0,times5 = 0;
        while(tempVec.size() < index){
            min_num = minimum(tempVec[times2] * 2,
                tempVec[times3] * 3,tempVec[times5] * 5);
            if(min_num == tempVec[times2] * 2){
                times2++;
            }
            if(min_num == tempVec[times3] * 3){
                times3++;
            }
            if(min_num == tempVec[times5] * 5){
                times5++;
            }
            tempVec.push_back(min_num);
        }
        return min_num;
    }
};
int main(){
    int temp;
    cin >> temp;
    Solution so;
    cout << so.GetUglyNumber_Solution(temp);
    return  0;
}