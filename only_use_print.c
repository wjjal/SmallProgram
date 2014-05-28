#include<stdio.h>


int func(int i , int n)
{
	return (i==n && printf("%d\n",i)) || (printf("%d\n",i) && func(i+1,n) && printf("%d\n",i));
}

void main(){
   func(1,5);
}