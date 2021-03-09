package edu.hit;

/**
 * 重建二叉树
 * */
public class JZ4 {
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) {
        if(pre == null || in == null || pre.length != in.length){
            return null;
        }
        return constructHelper(pre,0,pre.length - 1,in,0,in.length - 1);

    }


    private TreeNode constructHelper(int [] pre,int preStart,int preEnd,int [] in,int inStart,int inEnd){
        if(preStart > preEnd || inEnd < inStart){
            return null;
        }
        int rootIndex = inStart;
        for(int i = inStart;i <= inEnd;i ++){
            if(in[i] == pre[preStart]){
                rootIndex = i;
            }
        }
        TreeNode root = new TreeNode(pre[preStart]);
        root.left = constructHelper(pre,preStart + 1,preStart + rootIndex - inStart,in,inStart,rootIndex - 1);
        root.right = constructHelper(pre,preStart + (rootIndex - inStart) + 1,preEnd,in,rootIndex + 1,inEnd);
        return root;
    }


    class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public static void main(String[] args) {
        int[] pre = {1, 2, 3, 4, 5, 6, 7};
        int[] in = {3, 2, 4, 1, 6, 5, 7};
        JZ4 jz4 = new JZ4();
        TreeNode root = jz4.reConstructBinaryTree(pre, in);
        System.out.println();
    }
}
