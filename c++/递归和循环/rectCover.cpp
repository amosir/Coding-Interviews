#include<iostream>
using namespace std;
class Solution {
public:
    int rectCover(int number) {
        if(number <= 0){
            return 0;
        }
        if(number <= 2){
            return number;
        }
        return rectCover(number - 1) + rectCover(number - 2);
    }
};
int main(){
    Solution so;
    int temp;
    cin >> temp;
    cout << so.rectCover(temp);
    return 0;
}