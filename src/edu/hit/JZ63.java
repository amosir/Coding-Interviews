package edu.hit;

import java.util.Comparator;
import java.util.PriorityQueue;

/**
 * 数据流中的中位数
 * 思路: 用大顶堆和小顶堆分别保存中位数左边和右边的数，并且保证小顶堆和树大于大顶堆的数
 */
public class JZ63 {

    // 两个堆数据元素个数
    private int cnt = 0;

    // 最大堆保存中位数左边的数
    private PriorityQueue<Integer> leftMaxHeap = new PriorityQueue<>(new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
            return o2 - o1;
        }
    });

    // 最小堆保存中位数右边的数
    private PriorityQueue<Integer> rightMinHeap = new PriorityQueue<>();

    // 确保大顶堆元素个数总是大于等于小顶堆元素个数
    public void Insert(Integer num) {
        // 当前有偶数个数据，插入到左边
        if((cnt & 1) == 0){
            rightMinHeap.add(num);
            int temp = rightMinHeap.poll();
            leftMaxHeap.add(temp);
        }
        // 当前有奇数个数据，插入到右边
        else{
            leftMaxHeap.add(num);
            int temp = leftMaxHeap.poll();
            rightMinHeap.add(temp);
        }
        cnt ++;
    }

    public Double GetMedian() {
        // 一共有偶数个数，取大顶堆的最大值和小顶堆的最小值的平均数
        if(((cnt & 1) == 0)){
            return (rightMinHeap.peek() + leftMaxHeap.peek()) / 2.0;
        }
        // 一共有奇数个数，取大顶堆的最大值
        else{
            return Double.valueOf(leftMaxHeap.peek());
        }
    }

//    public static void main(String[] args) {
//        int[] test = {5,2,3,4,1,6,7,0,8};
//        JZ63 jz63 = new JZ63();
//        for(int temp : test){
//
//            jz63.Insert(temp);
//        }
//        System.out.println(jz63.GetMedian());
//    }
}
