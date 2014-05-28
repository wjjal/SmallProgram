//旋转数组的查找
//已知有序数组a[N]，从中间某个位置k（k未知，k=-1表示整个数组有序）分开，然后将前后两部分互换，
//得到新的数组，在该新数组的查找元素x。如：a[]={1,2,5,7,9,10,15}，从k=4分开，得到新数组a={9,10,15, 1,2,5,7}。

#include<stdio.h>
#include <stdlib.h>

int binary_search_rotate_arry(int *a, int n, int x);

void main(){
   int length,x;
   printf("Please input the length of array:\n");
   scanf("%d",&length);
   int *array = (int*)malloc(length * sizeof(int));
   printf("Please input the rotate array:\n");
   for(int i=0;i<length;i++){
	  scanf("%d",&array[i]);
   }
   printf("Please input the number you want to find:\n");
   scanf("%d",&x);
   int pos = binary_search_rotate_arry(array,length,x); 
   if(pos == -1)
      printf("Not Found!\n");
	else
	   printf("pos = %d",pos+1);
}

int binary_search_rotate_arry(int *a, int n, int x) {
   int low = 0;
   int high = n-1;
   while(low<=high){
      int mid = low + ((high - low) >> 1);
	  if(a[mid] == x){
	     return mid;
	  }
      if(a[mid] > a[low]) {
	     if(x < a[mid] && x >= a[low]) //左边有序
		    high = mid - 1;
		 else 
		    low= mid + 1;
	  } else if(a[mid] < a[high]) {
          if(x > a[mid] && x <= a [high]) //右边有序
		     low = mid + 1;
		   else
		     high = mid - 1;
	  } else {//处理1,0,1,1,1这样的情况，a[low]=a[mid]=a[high]
          if(a[mid] == a[low]) {
		     if(x < a[mid])
			    high = mid;
		     else
			    low = mid; 
          }		  
	  }	  
   }
   return -1;
} 