//LIS问题描述： 给定一个序列 An = a1 ,a2 ,  ... , an ，找出最长的子序列使得对所有 i < j ，ai < aj

#include <stdio.h>

int LIS(int a[],int length);
int BinarySearch(int b[],int length,int num);

void main(){
   int length,x;
   printf("Please input the length of array:\n");
   scanf("%d",&length);
   int a[length];
   printf("Please input the array:\n");
   for(int i=0;i<length;i++){
	  scanf("%d",&a[i]);
   }
   int result = LIS(a,length);
   printf("result = %d\n",result);
}

int LIS(int a[],int length){
   int b[length];
   b[0] = a[0];
   int max = 0;
   for(int i = 1;i<length;i++){
	   if(a[i] > b[max]) {
          max++;
		  b[max] = a[i];
	   } else {
	      int pos = BinarySearch(b,max,a[i]);
		  b[pos] = a[i];
       }	   
   }
   return max+1;
}

int BinarySearch(int b[],int length,int num){
    int left = 0,right = length;
	int mid;
	while(left<right){
	   mid = (left + right) >> 1;
	   if(b[mid] < num)
	      left = mid + 1;
       else if(b[mid] > num)
          right = mid - 1;
       else 
          return mid;	   
	}
	return left;
}