package edu.hit;

/**
 * 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
 */
public class JZ40 {
    public int[] FindNumsAppearOnce (int[] array) {
        if(array == null || array.length < 2){
            return new int[0];
        }
        // 所有数字异或的结果,所有相同数字的异或结果为0，最终结果是两个不同的数的异或结果
        int xor = 0;
        for(int num:array){
            xor ^= num;
        }
        // 两个不同的数的异或结果中至少有1个比特1,该变量用于寻找第一个比特1
        int indexOfOne = 1;
        while((xor & indexOfOne) == 0){
            indexOfOne <<= 1;
        }

        // 记录目标数
        int target1 = 0,target2 = 0;
        // 用这个比特1将原数组分成两组
        for(int num:array){
            if((num & indexOfOne) == 0){
                target1 ^= num;
            }else{
                target2 ^= num;
            }
        }
        if(target2 < target1){
            target1 = target1 ^ target2;
            target2 = target1 ^ target2;
            target1 = target2 ^ target1;
        }
        return new int[]{target1,target2};
    }

    public static void main(String[] args) {
        JZ40 jz40 = new JZ40();
        int[] arr = {1,4,1,6};
        System.out.println(jz40.FindNumsAppearOnce(arr));
    }
}
