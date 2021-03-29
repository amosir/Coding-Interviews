package edu.hit;

import java.util.Stack;

public class JZ5 {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();

    public void push(int node) {
        while(!stack2.empty()){
            stack1.push(stack2.pop());
        }
        stack1.push(node);
        while(!stack1.empty()){
            stack2.push(stack1.pop());
        }
    }

    public int pop() {
        return stack2.pop();
    }

    public static void main(String[] args) {
        JZ5 jz5 = new JZ5();
        for(int i = 0;i < 10;i++){
            jz5.push(i);
        }

        for(int i = 0;i < 10;i++){
            System.out.println(jz5.pop());
        }
    }
}
