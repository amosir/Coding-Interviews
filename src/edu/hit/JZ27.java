package edu.hit;

import java.lang.reflect.Array;
import java.util.*;

/**
 * 输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则按字典序打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
 */
public class JZ27 {
    // 标记数组
    private boolean visited[];

    // 临时记录一个排列
    private StringBuilder tempStr = new StringBuilder();

    public ArrayList<String> Permutation(String str) {
        // 边界情况
        if(str == null || str.length() == 0){
            return new ArrayList<>(0);
        }
        // 初始化标记数组
        visited = new boolean[str.length()];

        // 排序
        char[] chs = str.toCharArray();
        Arrays.sort(chs);

        // 返回结果
        Set<String> retSet = new HashSet<>();


        // 递归回溯求全排列
        helper(0,new String(chs),retSet);

        ArrayList ret = new ArrayList(retSet);
        Collections.sort(ret);


        return ret;
    }

    private void helper(int pos,String str,Set<String> result){
        if(pos == str.length()){
            result.add(tempStr.toString());
            return;
        }

        for(int i = 0;i < str.length();i ++){
            if(visited[i] == false){
                visited[i] = true;
                tempStr.append(str.charAt(i));
                helper(pos + 1,str,result);
                visited[i] = false;
                tempStr.deleteCharAt(tempStr.length() - 1);
            }
        }
    }

    public static void main(String[] args) {
        JZ27 jz27 = new JZ27();
        System.out.println(jz27.Permutation("aab"));

    }

}
