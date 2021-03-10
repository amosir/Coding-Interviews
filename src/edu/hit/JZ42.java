package edu.hit;

import java.util.ArrayList;

/**
 * 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
 * <p>
 * 双指针
 */
public class JZ42 {
    public ArrayList<Integer> FindNumbersWithSum(int[] array, int sum) {
        // 记录当前出现的最小乘积
        int minMultiply = Integer.MAX_VALUE;
        // 当前出现最小乘积时的索引
        int minI = -1, minJ = Integer.MAX_VALUE;
        for (int i = 0, j = array.length - 1; i < j; ) {
            // 和满足条件的情况
            if (array[i] + array[j] == sum) {
                // 比当前最小乘积小则更新最小积和对应两个数的索引
                if (array[i] * array[j] < minMultiply) {
                    minI = i;
                    minJ = j;
                    minMultiply = array[i] * array[j];
                }
                // 寻找下一对满足条件的两个数
                i++;
                j--;
            }
            // 和比目标值小则左边的索引加1
            else if (array[i] + array[j] < sum) {
                i++;
            }
            // 和比目标值大则右边的索引减1
            else {
                j--;
            }
        }
        if (minI == -1) {
            return new ArrayList<Integer>(0);
        } else {
            ArrayList<Integer> ret = new ArrayList<>(2);
            ret.add(array[minI]);
            ret.add(array[minJ]);
            return ret;
        }

    }

    public static void main(String[] args) {
        JZ42 jz42 = new JZ42();
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        System.out.println(jz42.FindNumbersWithSum(arr, 21));

    }
}
