package edu.hit;

public class JZ12 {
    public double Power(double base, int exponent) {
        if(base == 0 && exponent != 0){
            return 0;
        }
        if(base != 0 && exponent == 0){
            return 1;
        }
        boolean flag = true;
        if(exponent < 0){
            flag = false;
            exponent = -1 * exponent;
        }
        double result = 1;
        for(int i = 0;i < exponent;i++){
            result = result * base;
        }
        if(!flag){
            result = 1.0 / result;
        }
        return result;
    }

    public static void main(String[] args) {
        JZ12 jz12 = new JZ12();
        System.out.println(jz12.Power(2, -3));
    }
}
