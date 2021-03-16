package edu.hit;

/**
 *
 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */
public class JZ2 {
    public String replaceSpace (String s) {
        if(s == null || "".equals(s)){
            return "";
        }
        StringBuilder ret = new StringBuilder();
        for(int i = 0;i < s.length();i++){
            if(s.charAt(i) == ' '){
                ret.append("%20");
            }else{
                ret.append(s.charAt(i));
            }
        }
        return ret.toString();
    }

    public static void main(String[] args) {
        JZ2 jz2 = new JZ2();
        System.out.println(jz2.replaceSpace("We Are Happy"));
    }
}
