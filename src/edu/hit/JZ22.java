package edu.hit;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class JZ22 {

    class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;

        }

    }

    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        if(root == null){
            return new ArrayList<>(0);
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        ArrayList<Integer> ret = new ArrayList<>();
        while(!queue.isEmpty()){
            TreeNode temp = queue.poll();
            ret.add(temp.val);
            if(temp.left!=null){
                queue.add(temp.left);
            }
            if(temp.right!=null){
                queue.add(temp.right);
            }
        }
        return ret;
    }
}
