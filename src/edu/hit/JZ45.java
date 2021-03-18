package edu.hit;

import java.util.Arrays;

/**
 * 扑克牌顺子
 */
public class JZ45 {
    public boolean IsContinuous(int [] numbers) {
        int len = numbers.length;
        // 边界条件
        if(numbers == null || len < 5){
            return false;
        }

        // 排序
        Arrays.sort(numbers);

        // 0的个数
        int cntZero = 0;
        int gap = 0;
        for(int i = 0;i < len - 1;i++){
            // 0的个数
            if(numbers[i] == 0){
                cntZero++;
                continue;
            }
            // 有重复数的情况
            if(numbers[i + 1] == numbers[i]){
                return false;
            }

            // 相邻两个数的差值
            gap = gap + numbers[i+1] - numbers[i] - 1;

        }
        if(gap > cntZero){
            return false;
        }else{
            return true;
        }
    }

    public static void main(String[] args) {
        int[] nums = {1,3,2,5,4};
        JZ45 jz45 = new JZ45();
        System.out.println(jz45.IsContinuous(nums));
    }
}
