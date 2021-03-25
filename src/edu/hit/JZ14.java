package edu.hit;

public class JZ14 {

    static class ListNode {
        int val;
        ListNode next = null;

        public ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode FindKthToTail(ListNode pHead, int k) {
        if(k <= 0 || pHead == null){
            return null;
        }

        // 快慢指针，快指针比慢指针先移动 k - 1个节点
        ListNode fast = pHead,slow = pHead;
        for(int i = 0;i < k - 1;i ++){
            if(fast != null && fast.next != null){
                fast = fast.next;
            }
            // 链表长度比 k 小
            else{
                return null;
            }
        }
        // 快慢指针同时移动，快指针指向链表尾部时慢指针只在倒数第K个节点
        while(fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        return slow;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);
        head.next.next.next.next = new ListNode(5);
        JZ14 jz14 = new JZ14();
        ListNode ret = jz14.FindKthToTail(head,6);
        System.out.println();
    }
}
