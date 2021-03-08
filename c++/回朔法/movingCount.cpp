#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
private:    
    // 坐标各位之和
    int bitSum(int i,int j){
        int sum = 0;
        while(i > 0){
            sum += (i % 10);
            i /= 10;
        }
        while(j > 0){
            sum += (j % 10);
            j /= 10;
        }
        return sum;
    }
    int fillIn(int threshold, int rows, int cols,int i,int j,vector<bool> &flags){
        int cnt = 0;
        int k = i * cols + j;
        if(i >= 0 && i < rows && j >= 0 && j < cols &&
            !flags[k] && bitSum(i,j) <= threshold){
            
            flags[k] = true;
            // 左
            cnt = 1 + fillIn(threshold,rows,cols,i,j - 1,flags)
            // 右
            + fillIn(threshold,rows,cols,i,j + 1,flags)
            // 上
            + fillIn(threshold,rows,cols,i - 1,j,flags)+
            // 下
            + fillIn(threshold,rows,cols,i + 1,j,flags);
        }

        return cnt;
    }
public:
    
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0 || cols <= 0 || rows <= 0){
            return 0;
        }
        // 访问标记
        vector<bool> flags(rows * cols);
        for(int i = 0;i < rows;i++){
            int temp = i * cols;
            for(int j = 0;j < cols;j++){
                flags[temp + j] = false;
            }
        }
        // 从(0,0)开始
        return fillIn(threshold,rows,cols,0,0,flags); 
    }
};
int main(){
    Solution so;
    int threshhold,rows,cols;
    cin >> threshhold  >> rows >> cols;
    cout << so.movingCount(threshhold,rows,cols);
    return 0;
}