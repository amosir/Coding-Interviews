package edu.hit;

public class JZ49 {
    public int StrToInt(String str) {
        if(str == null || str.length() == 0){
            return 0;
        }

        // 返回数
        int ret = 0;

        // 正负号
        boolean flag = true;

        // 第一个字符可能是符号
        if(str.charAt(0) == '+'){
            flag = true;
        }else if(str.charAt(0) == '-'){
            flag = false;
        }else if((str.charAt(0) >= '0' && str.charAt(0) <= '9')){
            ret = str.charAt(0) - '0';
        }else{
            return 0;
        }
        for(int i = 1;i < str.length();i++){
            if(str.charAt(i) >= '0' && str.charAt(i) <= '9'){
                ret = ret * 10 + (str.charAt(i) - '0');
            }else{
                return 0;
            }
        }
        if(flag == false){
            ret = ret * -1;
        }
        return ret;
    }

    public static void main(String[] args) {
        JZ49 jz49 = new JZ49();
        System.out.println(jz49.StrToInt("1a33"));
    }
}
