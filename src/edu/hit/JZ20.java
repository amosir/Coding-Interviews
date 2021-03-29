package edu.hit;

import java.util.Scanner;
import java.util.Stack;

public class JZ20 {
    private Stack<Integer> stack = new Stack();
    private Stack<Integer> minStack = new Stack();

    public void push(int node) {
        stack.push(node);
        if(minStack.empty()){
            minStack.push(node);
        }else{
            if(minStack.peek() > node){
                minStack.push(node);
            }else{
                minStack.push(minStack.peek());
            }
        }
    }

    public void pop() {
        if(!stack.empty()){
            minStack.pop();
            stack.pop();
        }
    }

    public int top() {
        return stack.peek();
    }

    public int min() {
        return minStack.peek();
    }

    public static void main(String[] args) {
        JZ20 jz20 = new JZ20();
        int[] arr = {2, 1, 4, 5, 1, 3, 3};
        for(int i = 0;i < arr.length;i++){
            jz20.push(arr[i]);
        }
        System.out.println(jz20);
    }
}
