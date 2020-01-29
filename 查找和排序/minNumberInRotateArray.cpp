#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0){
            return 0;
        }
        int len = rotateArray.size();
        //最小值所在的索引
        int min = 0;
        for(int i = 0;i < len;i++){
            if(rotateArray[i] < rotateArray[min]){
                min = i;
            }
        }
        rotate(rotateArray,0,len - 1);
        rotate(rotateArray,len - min,len - 1);
        rotate(rotateArray,0,len - 1 - min);
        return rotateArray[0];
    }
    void rotate(vector<int> &vec,int start,int end){
        while(start < end){
            int temp = vec[start];
            vec[start] = vec[end];
            vec[end] = temp;
            start++;
            end--;
        }
    }
};
int main(){
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(2);
    Solution so;
    so.minNumberInRotateArray(vec);
    return 0;

}