package edu.hit;

public class JZ56 {

    static class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode deleteDuplication(ListNode pHead) {
        // 链表为空或者只有一个节点的情况
        if(pHead == null || pHead.next == null){
            return pHead;
        }
        // 前两个节点是重复节点
        if(pHead.val == pHead.next.val){
            ListNode pos = pHead.next;
            // 将前面和首节点相同的节点全部删除
            while(pos != null && pHead.val == pos.val){
                pos = pos.next;
            }
            return deleteDuplication(pos);
        }
        // 首节点不是重复节点，则对后一个节点继续进行迭代处理
        else{
            pHead.next = deleteDuplication(pHead.next);
            return pHead;
        }
    }
}
