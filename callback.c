//回调函数和排序
#include <stdio.h>

typedef struct stack {
    int low;
	int high;
} stack;

void swap(int array[],int i, int j){
    int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
int RandPartition(int array[],int lo,int hi) {
    int v=array[lo];
    while(lo < hi){
       while(lo < hi && v < array[hi])
          hi--;
	   array[lo] = array[hi];
	   while(lo < hi && v >= array[lo])
	      lo++;
       array[hi] = array[lo];
    }
    array[lo] = v;
    return lo;
}

void heapAdjust (int array[],int root,int range){
    int i = root;
	int temp = array[i];
	for(int j = i*2+1; j <= range; j = j*2+1){
	    if((j < range) && (array[j] < array[j+1]))
		   j++;
		if(temp < array[j]) {
		   array[i] = array[j];
           i = j;
		} else
		    break;
	}
	array[i] = temp;
}

void quicksort(int array[],int length){
    int lo = 0;
	int hi = length - 1;
	stack stack[length-1];
	stack[0].low = lo;
	stack[0].high = hi;
	int top = 0;
	while(top>=0){
	   int low = stack[top].low;
	   int high = stack[top].high;
	   int key = RandPartition(array,low,high);
	   top--;
	   if(low < key -1){
	      top++;
	      stack[top].low = low;
		  stack[top].high = key - 1;
	   }
	   if(high > key + 1){
	      top++;
		  stack[top].low = key + 1;
		  stack[top].high = high;
	   }
	}
}
    

void heapsort(int array[],int length){
    for(int i = (length-1)/2 ; i >= 0; i--){
	   heapAdjust(array,i,length);
	}
	for(int i = length - 1 ; i > 0 ; i--){
	   swap(array,0,i);
	   heapAdjust(array,0,i-1);
	}
}

void callback(void (*sort)(int[],int),int array[],int length) {
     sort(array,length);
}

void main(){
    int length = 7;
    int array1[] = {8,2,3,5,4,6,7};
	callback(quicksort,array1,length);
	for(int i = 0;i<length;i ++) {
	   printf("%d ",array1[i]);
	}
	printf("\n");
    int array2[] = {8,2,3,5,4,6,7};
	callback(heapsort,array2,length);
	for(int i = 0;i<length;i ++) {
	   printf("%d ",array2[i]);
	}
}