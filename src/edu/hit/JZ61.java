package edu.hit;

/**
 * 线索化二叉树
 */
public class JZ61 {

    int index = -1;

    static class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;

        }

    }

    String Serialize(TreeNode root) {
        if(root == null){
            return "#";
        }else{
            return root.val + "!" + Serialize(root.left) + "!" + Serialize(root.right);
        }
    }

    TreeNode Deserialize(String str) {
        String[] values = str.split("!");
        index++;
        if(index >= values.length){
            return null;
        }
        TreeNode root = null;
        if(!values[index].equals("#")){
            root = new TreeNode(Integer.valueOf(values[index]));
            root.left = Deserialize(str);
            root.right = Deserialize(str);
        }
        return root;
    }


    public static void main(String[] args) {
        JZ61 jz61 = new JZ61();
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        TreeNode treeNode = jz61.Deserialize(jz61.Serialize(root));
    }
}
