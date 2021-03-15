package edu.hit;

/**
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
 * n≤39
 */
public class JZ7 {
    public int Fibonacci(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        // 分别记录前面的两个数
        int formerOne = 1,formerTwo = 0,temp;
        for(int i = 2;i <= n;i++){
            temp = formerTwo + formerOne;
            formerTwo = formerOne;
            formerOne = temp;
        }
        return formerOne;
    }

    public static void main(String[] args) {
        JZ7 jz7 = new JZ7();
        System.out.println(jz7.Fibonacci(4));
    }
}
