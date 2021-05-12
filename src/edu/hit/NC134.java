package edu.hit;

/**
 * 股票(无限次交易)
 *
 * https://www.nowcoder.com/practice/9e5e3c2603064829b0a0bbfca10594e9?tpId=117&tqId=37846&companyId=665&rp=1&ru=%2Fcompany%2Fhome%2Fcode%2F665&qru=%2Fta%2Fjob-code-high%2Fquestion-ranking&tab=answerKey
 */
public class NC134 {
    public int maxProfit (int[] prices) {
        if(prices == null || prices.length == 0) return 0;
        int res = 0;
        for(int i = 1;i < prices.length;i++){
            int temp = prices[i] - prices[i - 1];
            if(temp > 0){
                res += temp;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        NC134 nc134 = new NC134();
        int[] arr = {5,4,3,2,1};
        System.out.println(nc134.maxProfit(arr));
    }
}
