// 一种报数游戏是从1开始连续报数，如果报到7的倍数（7，14，21，28……）或者包含数字7的数（7，17，27，37……）就用拍手代替这个数而不能报出。假设你连续听到m声拍手，问造成你听到m声拍手的第一下拍手所代表的数是几？

// 例如，你听到了两次连续的拍手，最小的可能这两次拍手是27和28，因此输出27。

// 输入m, 输出这m次连续的拍手第一下所代表的最小可能的数。 
// 题目说的还是较清楚的：

// 1、7的倍数

// 2、包含数字7的数

// 另外要求是连续拍手，最后输出是拍手的第一个数，当然这个数要求是最小可能。

// 0次 1

// 1次 7

// 2次 27 28

// 3次 70...

#include<stdio.h>

int includeseven(int n) {
    while(n > 0){
	   if( n%10 ==7 )
	      return 1;
	   else 
		  n = n/10;
	}
	return 0;
}

int getstartnum(int n){
   int i = 0, cur = 7;
   while(i < n){
      if( cur%7==0 || includeseven(cur))
	     i++;
	  else
	     i = 0;
      cur++;
   }
   return cur-n;
}

void main(){
   int n;
   printf("请输入听到的连续拍手数：");
   scanf("%d",&n);
   printf("第一下是%d",getstartnum(n));
}