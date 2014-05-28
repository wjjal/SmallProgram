//一个数组中有三个数字a、b、c只出现一次，其他数字都出现了两次。请找出三个只出现一次的数字。
#include <stdio.h>

void getThreeUnique(int a[], int n);
int lastBitOf1(int number);
void swap(int a[],int i ,int j);
void getTwoUnique(int a[],int n);

void main(){
  int array[] = {2, 4, 1, 4, 6, 5, 6, 1,9};
  int length = 9;
  getThreeUnique(array,length);
}

void getThreeUnique(int a[], int n) {
   if( n < 3){
     printf("numbers are less than 3!");
   }
   int xorResult = 0;
   for(int i=0;i<n;i++){
     xorResult ^= a[i];
   }
   int flags = 0;
   for(int i=0;i<n;i++){
      flags ^= lastBitOf1(xorResult ^ a[i]);
   }
   flags = lastBitOf1(flags);
   // get the first unique number
   int first = 0;
   for(int i=0;i<n;i++){
      if(lastBitOf1(a[i]^xorResult) == flags)
	     first ^= a[i];
   }
   printf("%d,",first);
   // move the first unique number to the end of array
   for(int i=0;i<n;i++){
      if(a[i]==first){
	    swap(a,i,n-1);
		break;
	  }
   }   
    // get the second and third unique numbers
    getTwoUnique(a, n-1);
}

int lastBitOf1(int number)
{
    return number & ~(number - 1);
}

void swap(int a[],int i ,int j){
    int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void getTwoUnique(int a[],int n)
{
    int xorResult = 0;
	for(int i=0;i<n;i++){
     xorResult ^= a[i];
    }   
    int diff = lastBitOf1(xorResult);   
    int first = 0;
    int second = 0;
    for(int i=0;i<n;i++){
	   if(diff & a[i])
          first ^= a[i];
       else
          second ^= a[i];
	}
    printf("%d,%d\n",first,second);
}