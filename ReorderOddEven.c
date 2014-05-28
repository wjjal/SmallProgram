//输入一个整数数组，调整数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。要求时间复杂度为O(n)。

#include <stdio.h>

void Reorder(int a[],int length);
int isOdd(int x);
int isEven(int x);

void main(){
    int length = 0;
    printf("Please input the length of array:\n");
	scanf("%d",&length);
	int array[length];
	printf("Please input the array:\n");
	for(int i=0;i<length;i++){
	   scanf("%d",&array[i]);
	}
	Reorder(array,length);
	for(int i=0;i<length;i++){
	   printf("%d ",array[i]);
	}
}

void Reorder(int a[],int length){
   int *left = a;
   int *right = &a[length-1];
   while(left < right) {
      if(isOdd(*left)){
         left++;
		 continue;
	  }
      if(isEven(*right)){
         right--;
		 continue;
	  }
      int temp = *left;
      *left = *right;
      *right = temp;	  
   }
}

int isOdd(int x){
   return (x&1)==1;
}

int isEven(int x){
   return (x&1)==0;
}