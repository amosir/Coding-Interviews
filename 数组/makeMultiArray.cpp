#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> ret(len);
        for(int i = 0;i < len;i++){
            int temp = 1;
            for(int j = 0;j < len;j++){
                if(j!=i){
                    temp = temp * A[j];
                }
            }
            ret[i] = temp;
        }
        return ret;
    }
};