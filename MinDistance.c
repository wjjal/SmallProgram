//给定一个数组，和两个在该数组中出现的数字，输出这两个数字出现的最小距离
#include <stdio.h>
#define INT_MAX 65535
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int minDistance(int A[], int size, int num1, int num2);

void main(){
   int array[] = {0,1,2,3,4,5,6,7,2,6};
   int dis = minDistance(array,10,2,6);
   printf("%d\n",dis);
}

int minDistance(int A[], int size, int num1, int num2)
{
	int num1_last_pos = -1;
	int num2_last_pos = -1;
	int min_dist = INT_MAX;
	for(int i = 0; i < size; ++i)
	{
		if(A[i] == num1)
		{
			num1_last_pos = i;
			if(num2_last_pos >= 0)
				min_dist = MIN(min_dist, num1_last_pos-num2_last_pos);
		}
		if(A[i] == num2)
		{
			num2_last_pos = i;
			if(num1_last_pos >= 0)
				min_dist = MIN(min_dist, num2_last_pos-num1_last_pos);
		}
	}
	return min_dist;
}
