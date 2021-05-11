package edu.hit;

/**
 * 数字翻译成字符串
 *
 * https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=117&tqId=37840&companyId=665&rp=1&ru=%2Fcompany%2Fhome%2Fcode%2F665&qru=%2Fta%2Fjob-code-high%2Fquestion-ranking&tab=answerKey
 */
public class NC116 {
    public int solve (String nums) {
        // 字符串为空或以0开头
        if(nums == null || nums.length() == 0 || nums.charAt(0) == '0') return 0;
        int len = nums.length();
        // dp[i]表示第i个位置之前的子串的翻译种数
        int[] dp = new int[len];
        dp[0] = 1;
        for(int i = 1;i < len;i++){
            // 当前位置不为0,将当前字符单独翻译
            if(nums.charAt(i) != '0'){
                dp[i] = dp[i - 1];
            }
            int num = (nums.charAt(i - 1)  - '0') * 10 + (nums.charAt(i) - '0');
            // 当前位置和前一个位置组成10~26之间的数
            if(num >= 10 && num <= 26){
                // 当前是第二个字符,加一种翻译方式
                if(i == 1){
                    dp[i] += 1;
                }
                // 当前不是第二个字符
                else{
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[len - 1];
    }

    public static void main(String[] args) {
        NC116 nc116 = new NC116();
        String str = "0";
        System.out.println(nc116.solve(str));
    }
}
