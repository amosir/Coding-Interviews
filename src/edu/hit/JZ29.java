package edu.hit;

import javafx.scene.layout.Priority;

import java.sql.PreparedStatement;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 最小的K个数
 * 利用最大堆，当前数小于堆顶元素时删除堆顶并加入当前元素
 */
public class JZ29 {

    public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
        // 边界条件
        if(input == null || k > input.length || k <= 0){
            return new ArrayList<>(0);
        }
        // 大顶堆
        PriorityQueue<Integer> bigHeap = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });

        for(int i = 0; i < input.length;i++){
            if(i < k){
                bigHeap.add(input[i]);
            }else{
                // 当前元素小于堆顶元素
                if(bigHeap.peek() > input[i]){
                    bigHeap.poll();
                    bigHeap.add(input[i]);
                }
            }
        }

        ArrayList<Integer> result = new ArrayList<>(k);
        while(!bigHeap.isEmpty()){
            result.add(bigHeap.remove());
        }

        return result;
    }

//    public static void main(String[] args) {
//        int[] input = {4,5,1,6,2,7,3,8};
//        JZ29 jz29 = new JZ29();
//        System.out.println(jz29.GetLeastNumbers_Solution(input, 4));
//    }

}
