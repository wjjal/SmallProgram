//给出一个数组A，找出一对 (i, j)使得A[i] <= A[j] (i <= j)并且j-i最大，
//若有多个这样的位置对，返回i最小的那一对。

//对于 i ，我们先找到 i 及其右端的最大元素的位置 j ，检查是否比当前记录的最优解更优，更新。
//然后考虑 j+1及其右端的最大元素位置是否大于等于A[i]，若是，令 j 等于该位置，重复如上过程，
//若否，那么从位置i+1重新开始，但j仍然从当前位置考虑即可

#include <stdio.h>

typedef struct peer {
   int begin;
   int end;
} peer;

peer findpeer(int array[],int length);

void main(){
    int array[] = {2,5,1,3,6,2,4,6,3,4};
	int length = 10;
	peer peer;
	peer = findpeer(array , length);
	printf("%d,%d",peer.begin,peer.end);
}

peer findpeer(int a[],int n){
   peer peer;
   int right_max_pos[n];
   right_max_pos[n-1] = n-1;
   for(int i = n-2;i>=0;i--){
       if(a[i] > a[right_max_pos[i+1]])
	      right_max_pos[i] = i;
	   else
	      right_max_pos[i] = right_max_pos[i+1];
   }
   int maxdis = 0;
   int i=0, j=0;
   while(j < n) {
       j = right_max_pos[j];
       if(a[j] >= a[i]){
	      if((j-i+1) > maxdis) {
		    peer.begin = i;
		    peer.end = right_max_pos[i];
		  }
		  j++;
	   }
	   else
	      i++;
   }
   return peer;
}