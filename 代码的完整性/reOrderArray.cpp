#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        if(len == 0 || len == 1){
            return;
        }
        vector<int> vec;
        for(int i = 0;i < len;i++){
            if((array[i] & 1)== 1){
                vec.push_back(array[i]);
            }
        }
        for(int j = 0;j < len;j++){
            if((array[j] & 1)== 0){
                vec.push_back(array[j]);
            }
        }
        for(int k = 0; k < len;k++){
            array[k] = vec[k];
        }
    }
};