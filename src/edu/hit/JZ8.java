package edu.hit;

/**
 * 青蛙跳台阶
 * 使用递归方式
 */
public class JZ8 {
    public int jumpFloor(int target) {
        if(target == 2){
            return 2;
        }else if(target == 1){
            return 1;
        }else{
            return jumpFloor(target - 1) + jumpFloor(target - 2);
        }
    }

//    public static void main(String[] args) {
//        JZ8 jz8 = new JZ8();
//        System.out.println(jz8.jumpFloor(4));
//    }
}
