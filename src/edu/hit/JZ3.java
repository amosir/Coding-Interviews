package edu.hit;

import java.util.ArrayList;

public class JZ3 {


    class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }


    private ArrayList<Integer> ret = new ArrayList<>();

    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        if(listNode != null){
            this.printListFromTailToHead(listNode.next);
            ret.add(listNode.val);
        }
        return ret;
    }

}
