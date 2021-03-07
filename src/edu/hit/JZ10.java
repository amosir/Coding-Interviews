package edu.hit;

/**
 * 矩形覆盖
 * 使用递归方式
 */
public class JZ10 {
    public int rectCover(int target) {
        if(target < 1){
            return 0;
        }else if(target == 1){
            return 1;
        }else if(target == 2){
            return 2;
        }else{
            return rectCover(target - 1) + rectCover(target - 2);
        }

    }
}
