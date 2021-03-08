#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    /**
     *  i和j是矩阵中的位置，len是目标串的长度，index是目标串的索引
     */
    bool find(char* matrix, int rows, int cols,int i,int j,
        char* str,int len,int index,vector<bool> &flags){
            int k = cols * i + j;
            if(i < 0 || j < 0 || i >= rows || 
                j >= cols || str[index] != matrix[k]
                || flags[k] == true){
                    return false;
                }
            if(index == len - 1){
                return true;
            }
            flags[k] = true;
            // 前
            if(find(matrix,rows,cols,i,j + 1,str,len,index + 1,flags)){
                return true;
            }
            //后
            if(find(matrix,rows,cols,i,j - 1,str,len,index + 1,flags)){
                return true;
            }
            //上
            if(find(matrix,rows,cols,i - 1,j,str,len,index + 1,flags)){
                return true;
            }
            // 下
            if(find(matrix,rows,cols,i + 1,j,str,len,index + 1,flags)){
                return true;
            }
            flags[k] = false;
            return false;
    }

    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        // 标记数组
        vector<bool> flags(rows * cols);
        for(int i = 0;i < rows;i++){
            int temp = i * cols;
            for(int j = 0;j < cols;j++){
                flags[temp + j] = false;
            }
        }
        // 目标串的长度
        int len = 0;
        for(;str[len] != '\0';len++){

        }
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(find(matrix,rows,cols,i,j,str,len,0,flags)){
                    return true;
                }
            }
        }
        return false;
    }


};