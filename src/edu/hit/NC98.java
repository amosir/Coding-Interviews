package edu.hit;

/**
 * 判断t1树中是否有与t2树拓扑结构完全相同的子树
 * <p>
 * https://www.nowcoder.com/practice/4eaccec5ee8f4fe8a4309463b807a542?tpId=117&tqId=37821&companyId=665&rp=1&ru=%2Fcompany%2Fhome%2Fcode%2F665&qru=%2Fta%2Fjob-code-high%2Fquestion-ranking&tab=answerKey
 */
public class NC98 {

    class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;
    }

    public boolean isContains(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2 == null) return true;
        if(root1 == null || root2 == null) return false;
        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        postOrder(root1, sb1);
        postOrder(root2, sb2);
        return sb1.toString().contains(sb2.toString());
    }

    private void postOrder(TreeNode root, StringBuilder sb){
        if(root == null) return;
        postOrder(root.left, sb);
        postOrder(root.right, sb);
        sb.append(root.val);
    }
}
