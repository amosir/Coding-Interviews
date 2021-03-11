package edu.hit;

import java.util.ArrayList;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.LinkedBlockingQueue;

/**
 * 滑动窗口的最大值
 */
public class JZ64 {
    public ArrayList<Integer> maxInWindows(int[] num, int size) {
        // 边界情况: 注意size可能非正
        if (num == null || num.length < size || num.length == 0 || size <= 0) {
            return new ArrayList<>(0);
        }

        // 返回数组
        ArrayList<Integer> ret = new ArrayList<>(num.length - size + 1);

        // 辅助队列，队首存放最大元素的索引
        Deque<Integer> queue = new LinkedList<>();
        for (int i = 0; i < num.length; i++) {
            // 当前元素比队列尾部元素大，则队尾元素不可能成为最大值，删除
            while (!queue.isEmpty() && num[queue.peekLast()] <= num[i]) {
                queue.pollLast();
            }

            // 队首元素不在窗口范围内，删除
            while (!queue.isEmpty() && queue.peekFirst() + size - 1 < i) {
                queue.pollFirst();
            }

            // 当前元素入队
            queue.addLast(i);
            // 从第一个窗口开始
            if (i + 1 >= size) {
                ret.add(num[queue.peekFirst()]);
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        JZ64 jz64 = new JZ64();
        int[] arr = {2, 3, 4, 2, 6, 2, 5, 1};
        System.out.println(jz64.maxInWindows(arr, 3));
    }
}
