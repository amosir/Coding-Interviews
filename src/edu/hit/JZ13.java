package edu.hit;

import java.util.Arrays;

/**
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
 * 所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
public class JZ13 {
    public int[] reOrderArray (int[] array) {
        if(array == null || array.length <= 1){
            return array;
        }
        // 记录上一个奇数的位置
        int lastOddPos = -1;
        for(int i = 0;i < array.length;i++){
            // 奇数
            if((array[i] & 1) == 1){
                int curNum = array[i];
                int j = i;
                // 上一个奇数到当前位置之间的数后移
                while(j > lastOddPos + 1){
                    array[j] = array[j - 1];
                    j --;
                }
                // 更新奇数位置
                lastOddPos++;
                array[lastOddPos] = curNum;
            }
        }
        return array;
    }

    public static void main(String[] args) {
        JZ13 jz13 = new JZ13();
        int[] arr = {1,2,3,4};
        int[] ret = jz13.reOrderArray(arr);
    }
}
