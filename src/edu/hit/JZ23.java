package edu.hit;

/**
 *
 */
public class JZ23 {
    public boolean VerifySquenceOfBST(int [] sequence) {
        // 空树不是二叉树
        if(sequence.length == 0){
            return false;
        }
        if(sequence.length == 1){
            return true;
        }
        return helper(sequence,0,sequence.length - 1);
    }

    private boolean helper(int[] sequence,int start,int end){
        if(start >= end){
            return true;
        }
        // rightStart指向右子树的第一个节点
        int rightStart = 0;
        for(;rightStart < end && sequence[rightStart] <= sequence[end];rightStart++){}

        // 右边序列一定全部大于根节点
        for(int i = rightStart;i < end;i++){
            if(sequence[i] <= sequence[end]){
                return false;
            }
        }
        // 递归判断左右子树序列
        return helper(sequence,0,rightStart - 1) && helper(sequence,rightStart,end - 1);
    }

    public static void main(String[] args) {
        int[] arr = {4,8,6,12,16,14,10};
        JZ23 jz23 = new JZ23();
        System.out.println(jz23.VerifySquenceOfBST(arr));
    }
}
