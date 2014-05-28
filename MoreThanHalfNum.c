//////////////////////////////////////////////////////////////////////////
// Input: an array with "length" numbers. A number in the array
// appear more than "length / 2 + 1" times.
// Output: If the input is valid, return the number appearing more than
// "length / 2 + 1" times. Otherwise, return 0 and set flag g_bInputInvalid
// to be true.
//////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool g_bInputInvalid = false;
int MoreThanHalfNum(int* numbers, int length);

void main(){
    int length = 0;
    printf("Please input the length of array:\n");
	scanf("%d",&length);
	int *array = (int*)malloc(length * sizeof(int));
	printf("Please input the array:\n");
	for(int i=0;i<length;i++){
	   scanf("%d",&array[i]);
	}

	int result = MoreThanHalfNum(array, length);
	if(g_bInputInvalid)
	   printf("error input\n");
	else
	   printf("result = %d",result);
}

int MoreThanHalfNum(int* numbers,  int length)
{
    if(numbers == NULL && length == 0)
    {
        g_bInputInvalid = true;
        return 0;
    }
 
    g_bInputInvalid = false;
 
    int result = numbers[0];
    int times = 1;
    for(int i = 1; i < length; ++i)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times++;
        else
            times--;
    }
 
    // verify whether the input is valid
    times = 0;
    for(int i = 0; i < length; ++i)
    {
        if(numbers[i] == result)
            times++;
    }
 
    if(times * 2 <= length)
    {
        g_bInputInvalid = true;
        result = 0;
    }
 
    return result;
}