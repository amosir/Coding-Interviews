package edu.hit;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 */
public class JZ60 {

    ArrayList<ArrayList<Integer>> Print(TreeNode pRoot) {
        if(pRoot == null){
            return new ArrayList<ArrayList<Integer>>(0);
        }

        // 辅助队列
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(pRoot);

        // 返回结果
        ArrayList<ArrayList<Integer>> ret = new ArrayList<>();
        // 保存每一层的结果
        ArrayList<Integer> layer = new ArrayList<>(1);

        // 当前层已出队列的节点数量和下一层的节点总数
        int currentCnt = 0,nextCnt = queue.size();
        while(!queue.isEmpty()){
            TreeNode temp = queue.poll();
            layer.add(temp.val);
            currentCnt ++;
            if(temp.left != null){
                queue.offer(temp.left);
            }
            if(temp.right != null){
                queue.offer(temp.right);
            }
            if(currentCnt == nextCnt){
                currentCnt = 0;
                nextCnt = queue.size();
                ret.add(layer);
                layer = new ArrayList<>(nextCnt);
            }
        }
        return ret;
    }

    class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;

        }

    }

}

