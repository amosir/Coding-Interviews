package edu.hit;

/**
 * 翻转单词顺序列
 */
public class JZ44 {
    public String ReverseSentence(String str) {
        if(str == null || str.trim().length() == 0){
            return str;
        }
        String[] words = str.split(" ");
        for(int i = 0,j = words.length - 1;i < j;i ++,j--){
            String temp = words[i];
            words[i] = words[j];
            words[j] = temp;
        }
        return String.join(" ",words);
    }

    public static void main(String[] args) {
        JZ44 jz44 = new JZ44();
        System.out.println(jz44.ReverseSentence("  "));
    }
}
