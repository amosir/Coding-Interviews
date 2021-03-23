package edu.hit;

/**
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 */
public class JZ55 {

    class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode EntryNodeOfLoop(ListNode pHead) {
        // 只有一个节点或两个节点
        if(pHead == null || pHead.next == null){
            return null;
        }

        // 快慢指针
        ListNode fast = pHead, slow = pHead;

        // 快慢指针第一次相遇点
        ListNode meet = null;
        while(fast!=null && fast.next != null){
            fast = fast.next.next;
            slow = slow.next;

            // 快慢指针相遇，将快指针指向链表头，每次移动一个单位
            if(fast == slow){
                meet = fast;
                fast = pHead;
                while(fast != slow){
                    fast = fast.next;
                    slow = slow.next;
                }
                return slow;
            }
        }
        return null;
    }
}
