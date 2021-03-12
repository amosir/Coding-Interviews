package edu.hit;

public class JZ33 {
    public int GetUglyNumber_Solution(int index) {
        // 1 ~ 6 都是丑数
        if(index <= 6){
            return index;
        }

        // 记录每一个丑数
        int[] uglyNums = new int[index];
        uglyNums[0] = 1;

        // 记录下一个需要和2，3，5相乘的丑数的位置
        int ofThree = 0, ofTwo = 0, ofFive = 0;
        for(int i = 1;i < index;i ++){
            // 下一个丑数一定是前面出现的丑数对2，3，5乘积的最小值
            int uglyNum = minNum(uglyNums[ofThree] * 3,uglyNums[ofTwo] * 2,uglyNums[ofFive] * 5);
            // 当前数已经和2相乘，所以不再需要和2相乘了
            if(uglyNum == uglyNums[ofTwo] * 2){
                ofTwo ++;
            }
            if(uglyNum == uglyNums[ofThree] * 3){
                ofThree++;
            }
            if(uglyNum == uglyNums[ofFive] * 5){
                ofFive ++;
            }
            uglyNums[i] = uglyNum;
        }
        return uglyNums[index - 1];

    }
    private int minNum(int a,int b,int c){
        int temp = (a < b ? a : b);
        return temp < c ? temp : c;
    }

    public static void main(String[] args) {
        JZ33 jz33 = new JZ33();
        System.out.println(jz33.GetUglyNumber_Solution(7));
    }
}
