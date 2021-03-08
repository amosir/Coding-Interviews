#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> &input, int k) {
        vector<int> ret;
        if(input.size()== 0 || k <= 0 || k > input.size()){
            return ret;
        }
        sort(input.begin(),input.end());
        for(int i = 0;i < k;i++){
            ret.push_back(input[i]);
        }
        return ret;
    }
};
int main(){
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(3);
    vec.push_back(8);
    Solution so;
    vector<int> ret = so.GetLeastNumbers_Solution(vec,4);
    cout << ret.back() << endl;
}