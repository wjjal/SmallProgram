//我们把只包含因子2、3和5的数称作丑数（UglyNumber）。
//例如6、8都是丑数，但14不是，因为它包含因子7。习惯上我们把1当做是第一个丑数。求按从小到大的顺序//的第1500个丑数。
#include <stdio.h>
#include <stdlib.h>
#define MIN(a,b,c) ((((a) < (b)) ? (a) : (b)) < (c) \
     ? (((a) < (b)) ? (a) : (b)) : (c)) 

int GetUglyNumber_Solution(int index);

void main(){
   int index;
   printf("Please input the index of uglynumber: ");
   scanf("%d",&index);
   int result = GetUglyNumber_Solution(index);
   printf("result = %d",result);
}

int GetUglyNumber_Solution(int index){
    if(index <= 0)
	   return 0;
	int *pUglyNumbers = (int *)malloc(index*sizeof(int));
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;
	int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;
	
	while(nextUglyIndex < index){
	   int min = MIN(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
       pUglyNumbers[nextUglyIndex] = min;
       while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
           ++pMultiply2;
       while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
           ++pMultiply3;
       while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
           ++pMultiply5;
       ++nextUglyIndex; 
	}
	return pUglyNumbers[index - 1];
}