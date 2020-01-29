#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int cutRope(int number) {
        if(number < 2 || number > 60){
            return 0;
        }else{
            // 由于必须要切一刀所以2和3时为1和2
            if(number == 2){
                return 1;
            }
            if(number == 3){
                return 2;
            }
            // vec[i] 表示长度为i的绳子切割若干段后的最大乘积
            vector<int> vec(number + 1);
            // 这里是子问题，即在此之前已经至少切了一刀，故这里不一样
            vec[0] = 0;
            vec[1] = 1;
            vec[2] = 2;
            vec[3] = 3;
            int max = 0;
            for(int i = 4;i <= number;i++){
                for(int j = 1;j <= i / 2;j ++){
                    int temp = vec[j] * vec[i - j];
                    if(temp > max){
                        max = temp;
                        vec[i] = max;
                    }
                }
            }
            return vec[number];
        }
    }
};
int main(){
    Solution so;
    int temp;
    cin >> temp;
    cout << so.cutRope(temp);
    return 0;
}