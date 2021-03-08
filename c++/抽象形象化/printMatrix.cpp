#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> ret;
        // 矩阵的上边界和左边界
        int rowBegin = 0,colBegin = 0;
        // 矩阵的下边界和右边界
        int rowEnd = matrix.size() - 1,colEnd = matrix[0].size() - 1;

        while(rowBegin <= rowEnd && colBegin <= colEnd){
            // 向右扫描
            for(int j = colBegin;j <= colEnd;j++){
                ret.push_back(matrix[rowBegin][j]);
            }
            // 向下扫描
            for(int i = rowBegin + 1;i <= rowEnd;i++){
                ret.push_back(matrix[i][colEnd]);
            }
            // 向左扫描，如果只有一行则不用执行，故需判断
            if(rowBegin!=rowEnd){
                for(int j = colEnd - 1;j >= colBegin;j--){
                    ret.push_back(matrix[rowEnd][j]);
                }
            }
            // 向上扫描，排除只有一列的情况
            if(colBegin!=colEnd){
                for(int i = rowEnd - 1;i >= rowBegin + 1;i--){
                    ret.push_back(matrix[i][colBegin]);
                }
            }

            // 缩小边界
            rowBegin++;
            rowEnd--;
            colBegin++;
            colEnd--;
        } 

        return ret;
    }
};
