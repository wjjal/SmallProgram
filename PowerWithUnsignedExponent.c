//实现函数double Power(double base, int exponent)，求base的exponent次方。不需要考虑溢出。
#include<stdio.h>

double PowerWithUnsignedExponent(double base, int exponent);

void main(){
    double base,result;
	int exponent;
    printf("please input base and exponent:\n");
	scanf("%lf%d",&base,&exponent);
	result = PowerWithUnsignedExponent(base,exponent);
	printf("result=%f\n",result);
}

double PowerWithUnsignedExponent(double base, int exponent)
 {
    int neg = 0;
    if(exponent < 0) {
	  neg = 1;
	  exponent = -exponent;
	}
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
 
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1)
        result *= base;
    if(neg == 1)
	    result = 1/result;
    return result;
}