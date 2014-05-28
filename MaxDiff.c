//在数组中，数字减去它右边的数字得到一个数对之差。求所有数对之差的最大值。例如在数组{2, 4, 1, 16, 7, 5, 11, 9}中，数对之差的最大值是11，是16减去5的结果。
#include <stdio.h>

int maxdiff_solution1(int a[],int n);
int maxdiff_solution2(int a[],int n);

void main() {
  int array[] = {2, 4, 1, 16, 7, 5, 11, 9};
  int length = 8;
  int maxdiff1 = maxdiff_solution1(array,length);
  int maxdiff2 = maxdiff_solution2(array,length);
  if(maxdiff1 == maxdiff2)
     printf("maxdiff=%d",maxdiff1);
  else 
     printf("There's something wrong in two solution!maxdiff1=%d,maxdiff2=%d",maxdiff1,maxdiff2);
}

int maxdiff_solution1(int a[],int n){
   int diff[n-1];
   for(int i=0;i<n-1;i++){
      diff[i] = a[i]-a[i+1];
   }
   int maxdiff = diff[0];
   int currentdiff = diff[0];
   for(int i=1;i<n-1;i++){
     currentdiff = ((currentdiff+diff[i])>0)?(currentdiff+diff[i]):0;
	 if(currentdiff>maxdiff)
	    maxdiff = currentdiff;
   }
   return maxdiff;
}

int maxdiff_solution2(int a[],int n){
   int max = a[0];
   int maxdiff = max - a[1];
   for(int i=2;i<n;i++){
       if(a[i-1]>max)
	     max = a[i-1];
	   else if (max-a[i] > maxdiff)
	     maxdiff = max -a[i];
   }
   return maxdiff;
}