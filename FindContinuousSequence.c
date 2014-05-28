//输入一个正数n，输出所有和为n连续正数序列。
//例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6和7-8。
#include <stdio.h>

void FindContinuousSequence(int n);
void PrintContinuousSequence(int small, int big);

void main(){
   int number;
   printf("Please input the number: ");
   scanf("%d",&number);
   FindContinuousSequence(number);
}

void FindContinuousSequence(int n){
   int sum = 1;
   int begin = 1, end = 1;
   while(end<n/2+2){
     end++;
	 sum += end;
	 while(sum > n){
	    sum -= begin;
		begin++;
	 }
	 if(sum == n){
	    PrintContinuousSequence(begin, end);
	 }	 
   }
}

void PrintContinuousSequence(int small, int big)
{
      for(int i = small; i <= big; ++ i)
            printf("%d ", i);

      printf("\n");
}