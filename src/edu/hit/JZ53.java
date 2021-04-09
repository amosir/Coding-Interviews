package edu.hit;

public class JZ53 {
    public boolean isNumeric (String str) {
        if(str == null || str.length() == 0){
            return false;
        }

        boolean hasE = false, hasNum = false, hasFlag = false;
        int len = str.length();
        for(int i = 0;i < len;i++){
            // E只能出现一次记且不能出现在尾部
            if(str.charAt(i) == 'E' || str.charAt(i) == 'e'){
                if(i == len - 1) return false;
                if(hasE) return false;
                hasE = true;
            }
            // +/-只能出现在首部或E之后且不能出现在尾部
            else if(str.charAt(i) == '+' || str.charAt(i) == '-') {
                // 第一次出现不在开头必须要在E后面
                if (!hasFlag && i > 0 && str.charAt(i - 1) != 'E' && str.charAt(i - 1) != 'e')
                    return false;
                // 不是第一次出现
                if (hasFlag && str.charAt(i - 1) != 'E' && str.charAt(i - 1) != 'e') return false;
                if(i == len - 1) return false;
                hasFlag = true;
            }
            // .不能出现在E后且不能出现在尾部
            else if(str.charAt(i) == '.'){
                // .不能出现在E后面，也不能出现两次
                if(hasE || hasNum || i == len - 1) return false;
                hasNum = true;
            }else if(str.charAt(i) < '0' || str.charAt(i) > '9'){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        JZ53 jz53 = new JZ53();
        System.out.println(jz53.isNumeric("1a3.14"));
    }
}
