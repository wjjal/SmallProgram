//输入数字n，按顺序输出从1最大的n位10进制数。比如输入3，则输出1、2、3一直到最大的3位数即999。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void Print1ToMaxOfNDigits(int n);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);
void PrintNumber(char* number);

void main(){
   int n;
   printf("Please input the number of digit: ");
   scanf("%d",&n);
   Print1ToMaxOfNDigits(n);
}

// Print numbers from 1 to the maximum number with n digits, in order
void Print1ToMaxOfNDigits(int n) {
   // 0 or minus numbers are invalid input
    if(n <= 0)
        return;
 
    char* number = (char*)malloc((n+1) * sizeof(char));
    number[n] = '\0';
 
    for(int i = 0; i < 10; ++i)
    {
        // first digit can be 0 to 9
        number[0] = i + '0';
 
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }
}
 
// length: length of number
// index: current index of digit in number for this round
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    // we have reached the end of number, print it
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }
 
    for(int i = 0; i < 10; ++i)
    {
        // next digit can be 0 to 9
        number[index + 1] = i + '0';
 
        // go to the next digit
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

// Print number stored in string, ignore 0 at its beginning
// For example, print "0098" as "98"
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);
 
    for(int i = 0; i < nLength; ++ i)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;
 
        if(!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }
 
    printf("\n");
}