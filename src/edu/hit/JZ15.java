package edu.hit;

import java.util.List;

public class JZ15 {

    static class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

    private ListNode reversedHead = null;

    public ListNode ReverseList(ListNode head) {
        if(head != null){
            ListNode next = head.next;
            head.next = reversedHead;
            reversedHead = head;
            this.ReverseList(next);
        }
        return reversedHead;
    }

    public static void main(String[] args) {
        JZ15 jz15 = new JZ15();
        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        ListNode r = jz15.ReverseList(head);
        System.out.println(r);
    }
}
