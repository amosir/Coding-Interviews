package edu.hit;

public class JZ18 {

    class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;
        }
    }

    public TreeNode Mirror(TreeNode pRoot) {
        if(pRoot == null){
            return null;
        }else{
            TreeNode left = Mirror(pRoot.left);
            TreeNode right = Mirror(pRoot.right);
            pRoot.left = right;
            pRoot.right = left;
        }
        return pRoot;
    }
}
