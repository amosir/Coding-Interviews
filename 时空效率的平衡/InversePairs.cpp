#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    int cnt = 0;
public:
    int InversePairs(vector<int> data) {
        int len = data.size();
        if(len > 0){
            divide(data,0,len - 1);
        }
        return cnt;
    }
    void merge(vector<int> &vec,int start,int mid,int end){
        // 辅助数组
        vector<int> temp(end - start + 1);
        // i用于遍历第一段,j用于遍历第二段
        int i = start,j = mid + 1,k = 0;
        while(i <= mid && j <= end){
            // 第一段比第二段当前元素小，则较小者入栈
            if(vec[i] <= vec[j]){
                temp[k++] = vec[i++];
            }
            // 第一段当前元素比第二段当前元素大，则构成逆序，由于右侧数组
            // 是有序的，所以逆序数等于当前第二段j之前的元素个数
            else{
                temp[k++] = vec[j++];
                cnt += (mid - i + 1);
                cnt %= 1000000007;
            }
        }

        // 将两端序列剩余的元素添加到临时数组
        while(i <= mid){
            temp[k++] = vec[i++];
        }
        while(j <= end){
            temp[k++] = vec[j++];
        }
        // temp中的元素有序，将其复制到原数组  
        for(int k = 0;k < end - start + 1;k++){
            vec[start + k] = temp[k];
        }
    }
    void divide(vector<int> &vec,int start,int end){
        if(start < end){
            int mid = (start + end) >> 1;
            divide(vec,start,mid);
            divide(vec,mid + 1,end);
            merge(vec,start,mid,end);
        }
    }
};

int main(){
    Solution so;
    vector<int> vec;
    int co;
    cin >> co;
    for(int i = 0;i < co;i++){
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    cout << so.InversePairs(vec);
    return 0;
}