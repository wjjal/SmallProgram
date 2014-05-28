//给定一个正整数数组如[2,5,1,2,3,4,7,7,6]，数组中每个数代表一个墙的高度，如图，
//问：往墙里倒水，墙之间的水坑总共可以装多少水呢？
//题目详见http://blog.csdn.net/yutianzuijin/article/details/16853041

#include<stdio.h>
#include <stdlib.h>

int ArrayWall(int array[],int length);

int main()
{
    int size;
    printf("please input the length of array:");
	scanf("%d",&size);
	int *array = (int*)malloc(size * sizeof(int));
	printf("array wall:\n");
	for(int i = 0; i < size; i++)
		scanf("%d",&array[i]);
    printf("water = %d\n",ArrayWall(array,size));
	return 0;
}

int ArrayWall(int array[],int length)
{
	if(length < 3)
	{
		return 0 ;
	}
	int left_index = 0;
	int right_index = length - 1 ;
	int left_max = array[left_index];
	int right_max = array[right_index];
	int count = 0;
	while (left_index != right_index) {
       if(left_max < right_max){
	      left_index++;
		  if(array[left_index] > left_max)
		     left_max = array[left_index];
		  else
		     count += left_max - array[left_index];
	   } else {
	      right_index--;
		  if(array[right_index] > right_max)
		     right_max = array[right_index];
		  else
		     count += right_max - array[right_index];
	   }
	}	
	return count ;
}