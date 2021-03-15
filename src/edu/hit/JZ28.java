package edu.hit;

/**
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
 * 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 */
public class JZ28 {
    public int MoreThanHalfNum_Solution(int [] array) {
        // 记录目标数
        int target = 0;
        // 抵消之后的次数
        int cnt = 0;

        // 寻找众数
        for(int i = 0;i < array.length;i++){
            if(cnt == 0){
                cnt++;
                target = array[i];
            }else{
                if(target == array[i]){
                    cnt++;
                }else{
                    cnt--;
                }
            }
        }

        // 计算次数是否超过一半
        if(cnt > 0){
            cnt = 0;
            for(int i = 0;i < array.length;i++){
                if(array[i] == target){
                    cnt++;
                }
            }
            if(cnt * 2 > array.length){
                return target;
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        JZ28 jz28 = new JZ28();
        int[] arr = {1,2,3,2,2,2,5,4,2};
        System.out.println(jz28.MoreThanHalfNum_Solution(arr));

    }
}
