//三色旗排序问题

#include <stdio.h>

void sort(int array[],int length);
void swap(int array[],int a,int b);

void main(){  
   int length = 10;
   int array[] = {0,1,2,1,1,2,0,2,1,0};
   for(int i = 0;i < length;i++){
       printf("%d",array[i]);
   }
   printf("\n");
   sort(array,length);
   for(int i = 0;i < length;i++){
       printf("%d",array[i]);
   }
}

void sort(int array[],int length){
   int begin = 0;
   int current = 0;
   int end = length-1;
   while(current<=end){
       if(array[current] == 0){
	     swap(array,current,begin);
		 begin++;
		 current++;
		}
		else if (array[current] == 1){
		   current++;
		}
		else {
		   swap(array,current,end);
		   end--;
		}
   }
}

void swap(int array[],int a,int b){
    int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}