package edu.hit;

/**
 * 子数组最大乘积
 *
 * https://www.nowcoder.com/practice/9c158345c867466293fc413cff570356?tpId=117&tqId=37785&companyId=665&rp=1&ru=%2Fcompany%2Fhome%2Fcode%2F665&qru=%2Fta%2Fjob-code-high%2Fquestion-ranking&tab=answerKey
 */
public class NC83 {
    public double maxProduct(double[] arr) {
        if(arr == null || arr.length == 0) return 0;
        // maxProduct记录上一个位置之前的最大值, minProduct表示上一个位置之前的最小值
        // res表示全局最大值
        double maxProduct = arr[0],minProduct = arr[0], res = arr[0];
        for(int i = 1;i < arr.length;i++){
            double temp_max = maxProduct;
            // 更新当前位置的最大值和最小值
            maxProduct = Math.max(arr[i], Math.max(maxProduct * arr[i], minProduct * arr[i]));
            minProduct = Math.min(arr[i], Math.min(temp_max * arr[i], minProduct * arr[i]));
            res = Math.max(res, maxProduct);
        }
        return res;
    }

    public static void main(String[] args) {
        NC83 nc83 = new NC83();
        double arr[] = {-2.5,4,0,3,0.5,8,-1};
        System.out.println(nc83.maxProduct(arr));
    }
}
