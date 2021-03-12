package edu.hit;

/**
 * 旋转数组的最小数字
 *
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 * 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
 */
public class JZ6 {
    public int minNumberInRotateArray(int [] array) {
        if(array == null || array.length == 0){
            return 0;
        }
        int left = 0, right = array.length - 1;
        while(left < right){
            int mid = left + (right - left) / 2;

            // mid比右边界值大，最小债在右边
            if(array[mid] > array[right]){
                left  =  mid + 1;
            }
            // mid位置比右边界值小，最小值不可能在右边
            else if(array[mid] < array[right]){
                right = mid;
            }
            // mid位置和右边界值相等，无法判断，逐步缩小
            // 比如10111、11101
            else{
                right--;
            }
        }
        return array[left];
    }

    public static void main(String[] args) {
        JZ6 jz6 = new JZ6();
        int[] arr = {3,4,5,1,2};
        System.out.println(jz6.minNumberInRotateArray(arr));
    }
}
