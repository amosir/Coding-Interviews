package edu.hit;

/**
 * 平衡二叉树
 */
public class JZ39 {
    public boolean IsBalanced_Solution(TreeNode root) {
        if(root == null){
            return true;
        }
        if(IsBalanced_Solution(root.left) && IsBalanced_Solution(root.right)
                && Math.abs(getHeight(root.left) - getHeight(root.right)) <= 1){
            return true;
        }
        return false;

    }

    private int getHeight(TreeNode root){
        if(root == null){
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }




    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }
}
