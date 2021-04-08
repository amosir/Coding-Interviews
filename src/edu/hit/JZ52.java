package edu.hit;

public class JZ52 {

    // 递归方式
    public boolean match (String str, String pattern) {
        // 模式串为空时匹配串必须为空
        if(pattern.length() == 0){
            return str.length() == 0;
        }

        // 第一个位置匹配
        boolean match = (str.length() > 0 && (str.charAt(0) == pattern.charAt(0) || pattern.charAt(0) == '.'));
        // 含有*的情况
        if(pattern.length() > 1 && pattern.charAt(1) == '*'){
            return match(str,pattern.substring(2)) || (match && match(str.substring(1),pattern));
        }
        // 不含*的情况
        else{
            return match && match(str.substring(1),pattern.substring(1));
        }
    }

    // 动态规划方式
    // https://jishuin.proginn.com/p/763bfbd2a5d5
    public boolean dpMatch (String str, String pattern) {
        int strLen = str.length();
        int patternLen = pattern.length();
        // 记录串str的前i个字符和pattern的前j个字符是否匹配
        boolean[][] dp = new boolean[strLen + 1][patternLen + 1];
        // 空串和空模式串匹配
        dp[0][0] = true;
        // 匹配串为空，需要模式串的偶数位全部为*
        for(int j = 0;j < patternLen;j++){
            if(pattern.charAt(j) == '*'){
                dp[0][j+1] = dp[0][j - 1];
            }
        }

        for(int i = 0;i < strLen;i++){
            for(int j = 0;j < patternLen;j++){
                if(str.charAt(i) == pattern.charAt(j) || pattern.charAt(j) == '.'){
                    dp[i+1][j+1] = dp[i][j];
                }else if(pattern.charAt(j) == '*'){
                    if(str.charAt(i)!=pattern.charAt(j - 1) && pattern.charAt(j - 1) != '.'){
                        dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    }else{
                        dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i][j + 1] || dp[i + 1][j];
                    }
                }
            }
        }

        return dp[strLen][patternLen];
    }

    public static void main(String[] args) {
        JZ52 jz52 = new JZ52();
        System.out.println(jz52.dpMatch("", ".*"));

    }
}
