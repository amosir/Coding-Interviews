package edu.hit;

import java.util.Arrays;

/**
 * 连续子数组的最大和
 *
 * 动态规划
 *
 * 输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为 O(n).
 */
public class JZ30 {

    /**
     * 有数组方式
     * @param array
     * @return
     */
    public int FindGreatestSumOfSubArray(int[] array) {
        // 数组存放到每个元素为止的最大子数组和
        int[] subArraySum = new int[array.length];
        Arrays.fill(subArraySum,0);
        subArraySum[0] = array[0];

        // 当前最大子数组和
        int maxSum = subArraySum[0];
        for(int i = 1;i < array.length;i++){
            if(subArraySum[i - 1] + array[i] > array[i]){
                subArraySum[i] = subArraySum[i - 1] + array[i];
            }else{
                subArraySum[i] = array[i];
            }
            if(subArraySum[i] > maxSum){
                maxSum = subArraySum[i];
            }
        }
        return maxSum;
    }

//    public static void main(String[] args) {
//        int[] arr = {1,-2,3,10,-4,7,2,-5};
//        JZ30 jz30 = new JZ30();
//        System.out.println(jz30.FindGreatestSumOfSubArray(arr));
//    }

    /**
     * 无数组方式
     * @param array
     * @return
     */
    public int FindGreatestSumOfSubArray2(int[] array) {
        int maxSum = array[0];
        int tempSum = array[0];
        for(int i = 1;i < array.length;i++){
            if(tempSum + array[i] > array[i]){
                tempSum = tempSum + array[i];
            }else{
                tempSum = array[i];
            }
            if(tempSum > maxSum){
                maxSum = tempSum;
            }
        }
        return maxSum;
    }
}
