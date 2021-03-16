package edu.hit;

/**
 * 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,
 * 要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！
 */
public class JZ43 {
    public String LeftRotateString(String str,int n) {
        if(str == null || str.length() <= 1 || n % str.length() == 0){
            return str;
        }
        int shift = n % str.length();
        char[] elements = str.toCharArray();
        rotateHelper(elements,0,elements.length - 1);
        rotateHelper(elements,elements.length - shift,elements.length - 1);
        rotateHelper(elements,0,elements.length - shift - 1);
        return String.valueOf(elements);
    }

    private void rotateHelper(char[] arr,int start,int end){
        while(start < end){
            char temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start ++;
            end --;
        }
    }

    public static void main(String[] args) {
        JZ43 jz43 = new JZ43();
        System.out.println(jz43.LeftRotateString("abcXYZdef", 3));
    }
}
