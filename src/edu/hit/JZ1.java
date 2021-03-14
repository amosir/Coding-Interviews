package edu.hit;

/**
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */
public class JZ1 {
    public boolean Find(int target, int [][] array) {
        if(array == null || array.length <= 0 || array[0].length <= 0){
            return false;
        }
        // 从左下角开始寻找
        for(int i = array.length - 1,j = 0;j < array[0].length && i >= 0;){
            if(array[i][j] == target){
                return true;
            }
            // 当前元素比目标值大则向上寻找
            else if(array[i][j] > target) {
                i--;
            }
            // 当前元素比目标值小则向右寻找
            else{
                j ++;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        JZ1 jz1 = new JZ1();
        int[][] arr = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
        System.out.println(jz1.Find(7, arr));
    }
}
