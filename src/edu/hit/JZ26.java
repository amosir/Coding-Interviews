package edu.hit;

import sun.tools.asm.Cover;

/**
 * 二叉搜索树与双向链表
 * 递归方式
 */
public class JZ26 {

    private class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;
        }
    }

    private TreeNode pre = null;

    public TreeNode Convert(TreeNode pRootOfTree) {
        if(pRootOfTree == null){
            return null;
        }

        // 线索化
        ConvertHelper(pRootOfTree);

        // 寻找链表的头结点
        while(pRootOfTree.left != null){
            pRootOfTree = pRootOfTree.left;
        }
        return pRootOfTree;
    }

    private void ConvertHelper(TreeNode pRootOfTree){
        if(pRootOfTree == null){
            return;
        }
        ConvertHelper(pRootOfTree.left);
        if(pre!=null){
            pre.right = pRootOfTree;
            pRootOfTree.left = pre;
        }
        pre = pRootOfTree;
        ConvertHelper(pRootOfTree.right);
    }
}

