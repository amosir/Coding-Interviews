package edu.hit;

/**
 * 	数字在排序数组中出现的次数
 */
public class JZ37 {
    public int GetNumberOfK(int [] array , int k) {
        // 边界检查
        if(array == null || array.length == 0){
            return 0;
        }
        // 左右指针，注意上界是第一个大于k的元素，因此right初始值取值array.length
        int left = 0, right = array.length;

        // 上下界
        int lowerBound = 0, higherBound = 0;

        // 上界，即第一个大于k的元素的位置
        while (left < right){
            int mid = left + (right - left) / 2;
            if(array[mid] > k){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        higherBound = right;
        // 下界，即第一个等于k的元素的位置
        left = 0;
        right = array.length;
        while (left < right){
            int mid = left + (right - left) / 2;
            if(array[mid] < k){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        lowerBound = left;
        return higherBound - lowerBound;
    }

    public static void main(String[] args) {
        JZ37 jz37 = new JZ37();
        int[] arr = {1,2,3,3,3,3};
        System.out.println(jz37.GetNumberOfK(arr, 3));
    }
}
