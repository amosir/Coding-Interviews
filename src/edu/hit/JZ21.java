package edu.hit;

import java.util.Stack;
/**
 * 设计一个辅助栈和一个指针，指针默认指向序列第一个元素，先入栈，每次入栈
 * 后判断栈顶是否与序列的第一个元素相等，不相等继续入栈，相
 * 等时弹出栈顶，指针后移一位，然后继续判断此时栈顶是否与指
 * 针指向的值相等，如果相等继续弹出栈顶，一直比较到栈为空，进
 * 行下一轮入栈或者是循环结束，最后如果辅助栈为空，说明该序列
 * 可能是该压栈序列的弹出序列。
 */
public class JZ21 {
    public boolean IsPopOrder(int [] pushA,int [] popA) {
        if(pushA == null || popA == null || pushA.length != popA.length){
            return false;
        }
        Stack<Integer> stack = new Stack();
        int index = 0;
        for(int i = 0;i < pushA.length;i++){
            stack.push(pushA[i]);
            while(!stack.empty() && stack.peek() == popA[index]){
                stack.pop();
                index++;
            }
        }
        return stack.empty();
    }
}
