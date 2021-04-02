package edu.hit;

import java.lang.reflect.Array;
import java.util.*;

/**
 * 之字形打印二叉树
 */
public class JZ59 {
    private static class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;

        }
    }

    public ArrayList<ArrayList<Integer>> Print(TreeNode pRoot) {

        // 空树
        if(pRoot == null){
            return new ArrayList<>(0);
        }
        // 返回结果
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        // 当前行的值
        ArrayList<Integer> curLayerVals = new ArrayList<>();
        // 奇数层的辅助队列
        Deque<TreeNode> oddLayerNodes = new LinkedList<>();
        // 偶数层的辅助队列
        Deque<TreeNode> evenLayerNodes = new LinkedList<>();
        oddLayerNodes.add(pRoot);

        while(!oddLayerNodes.isEmpty() || !evenLayerNodes.isEmpty()){
            TreeNode temp;
            // 当前为奇数层
            while(!oddLayerNodes.isEmpty()){
                temp = oddLayerNodes.pollLast();
                // 从左向右压栈
                if(temp.left!=null){
                    evenLayerNodes.add(temp.left);
                }
                if(temp.right!=null){
                    evenLayerNodes.add(temp.right);
                }
                curLayerVals.add(temp.val);
            }
            // 用当前层元素个数作为判别条件
            if(!curLayerVals.isEmpty()){
                ret.add(curLayerVals);
                curLayerVals = new ArrayList<>(evenLayerNodes.size());
            }

            // 当前为偶数层
            while(!evenLayerNodes.isEmpty()){
                temp = evenLayerNodes.pollLast();
                // 从右向左压栈
                if(temp.right!=null){
                    oddLayerNodes.add(temp.right);
                }
                if(temp.left!=null){
                    oddLayerNodes.add(temp.left);
                }

                curLayerVals.add(temp.val);
            }
            if(!curLayerVals.isEmpty()){
                ret.add(curLayerVals);
                curLayerVals = new ArrayList<>(oddLayerNodes.size());
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        JZ59 jz59 = new JZ59();
        TreeNode root = new TreeNode(8);
        root.left = new TreeNode(6);
        root.right = new TreeNode(10);
        root.left.left = new TreeNode(5);
        root.left.right = new TreeNode(7);
        root.right.left = new TreeNode(9);
        root.right.right = new TreeNode(11);
        jz59.Print(root);
    }
}
