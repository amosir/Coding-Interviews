#include<iostream>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str,int length) {
       for(int i = 0;i < length;i++){
           if(str[i] == ' '){
               // 空格后面的字符向后移动
               for(int j = length - 1;j > i;j--){
                   str[j+2] = str[j];
               }
               // 修改总长度
               length  +=  2;
               str[i++] = '%';
               str[i++] = '2';
               str[i] = '0';
           }
       }
       str[length] =  '\0';
	}
};