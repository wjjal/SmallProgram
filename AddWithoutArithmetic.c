//不用 + - * /实现加法
#include <stdio.h>

int AddWithoutArithmetic(int num1, int num2);

void main(){
    int a,b,result;
    printf("please input two number:\n");
	scanf("%d%d",&a,&b);
	result = AddWithoutArithmetic(a,b);
	printf("The result %d add %d is %d\n",a,b,result);
}
int AddWithoutArithmetic(int num1, int num2)
{
        if(num2 == 0)
           return num1;
        int sum = num1 ^ num2;
        int carry = (num1 & num2) << 1;
        return AddWithoutArithmetic(sum, carry);
}