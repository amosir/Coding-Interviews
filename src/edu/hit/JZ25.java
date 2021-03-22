package edu.hit;

/**
 * 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点）
 * ，请对此链表进行深拷贝，并返回拷贝后的头结点.
 */
public class JZ25 {

    class RandomListNode {
        int label;
        RandomListNode next = null;
        RandomListNode random = null;

        RandomListNode(int label) {
            this.label = label;
        }
    }

    public RandomListNode Clone(RandomListNode pHead) {
        // 边界条件
        if(pHead == null){
            return null;
        }
        // 原链表主链的当前节点
        RandomListNode pos = pHead;
        // 复制链表的头尾节点
        RandomListNode head = null;
        RandomListNode end = null;
        while(pos != null){
            // 第一个节点作为头结点
            if(head == null){
                head = new RandomListNode(pos.label);
                end = head;
            }
            // 非第一个节点
            else{
                end.next = new RandomListNode(pos.label);
                end = end.next;
            }
            // 复制当前节点指向的随机节点
            if(pos.random != null){
                end.random = new RandomListNode(pos.random.label);
            }
            // 继续处理下一个位置
            pos = pos.next;
        }
        return head;
    }
}
