package edu.hit;

public class JZ16 {

    class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

    public ListNode Merge(ListNode list1, ListNode list2) {
        // 有一个链表为空的情况直接返回非空的链表
        if(list1 == null) return list2;
        if(list2 == null) return list1;

        // 合并链表的头结点,合并链表的尾结点,两个待合并链表的当前节点
        ListNode mergedHead = null,mergedPos = null, list1Pos = list1, list2Pos = list2;

        // 两个链表都没有遍历到末尾
        while(list1Pos != null && list2Pos != null){

            // list1的当前节点比list2的当前节点值小，插入list1的当前节点
            if(list1Pos.val <= list2Pos.val){
                // 如果合并链表为空则当前较小的节点成为头结点
                if(mergedHead == null){
                    mergedHead = list1;
                    mergedPos = mergedHead;
                    list1Pos = list1Pos.next;
                }else{
                    mergedPos.next = list1Pos;
                    mergedPos = mergedPos.next;
                    list1Pos = list1Pos.next;
                }
            }else{
                if(mergedHead == null){
                    mergedHead = list2;
                    mergedPos = mergedHead;
                }else{
                    mergedPos.next = list2Pos;
                    mergedPos = mergedPos.next;
                    list2Pos = list2Pos.next;
                }
            }
        }

        // 有一个链表遍历到结尾后直接将另一个链表接到合并链表的尾部即可
        if(list1Pos != null){
            mergedPos.next = list1Pos;
        }else{
            mergedPos.next = list2Pos;
        }
        return mergedHead;
    }

}
