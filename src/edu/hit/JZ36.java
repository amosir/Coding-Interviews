package edu.hit;

public class JZ36 {

    public class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
        // pos1和pos2 指向较长链表的头结点，这里先假设链表1更长
        ListNode pos1 = pHead1, pos2 = pHead2;

        // 两个链表的长度和长度差
        int len1 = 0,len2 = 0,distance = 0;

        // 计算链表的长度
        while(pos1 != null){
            len1 ++;
            pos1 = pos1.next;
        }

        while(pos2 != null){
            len2 ++;
            pos2 = pos2.next;
        }

        if(len1 > len2){
            distance = len1 - len2;
            pos1 = pHead1;
            pos2 = pHead2;
        }
        // 链表二更长，pos1指向链表2的头节点
        else{
            distance = len2 - len1;
            pos1 = pHead2;
            pos2 = pHead1;
        }

        // 较长的链表先移动distance个长度
        for(int i = 0;i < distance;i++){
            pos1 = pos1.next;
        }

        // 剩下的链表节点数一样
        while(pos1 != null && pos2 != null){
            if(pos1 == pos2){
                return pos1;
            }
            pos1 = pos1.next;
            pos2 = pos2.next;
        }
        return null;
    }
}
