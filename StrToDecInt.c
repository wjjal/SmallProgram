//输入一个表示整数的字符串，把该字符串转换成整数并输出，例如输入字符串"345"，则输出整数345。
//给定函数原型int StrToInt(const char *str) ，完成函数StrToInt，实现字符串转换成整数的功能，不得用库函数atoi。
#include <stdio.h>
int StrToDecInt(const char* str);

void main(){
     char input[20];
     char* str;
	 int result;
     printf("Please input the number:");
	 scanf("%s",&input);
	 str = input;
	 result = StrToDecInt(str);
	 printf("output=%d\n",result);
}

int StrToDecInt(const char* str)    
{    
    static const int MAX = (int)((unsigned)~0 >> 1);
    printf("MAX=%d\n",MAX);    
    static const int MIN = -(int)((unsigned)~0 >> 1) - 1;   
    printf("MIN=%d\n",MIN);	
    static const int MAX_DIV = (int)((unsigned)~0 >> 1) / 10;    
    static const int MIN_DIV = (int)((((unsigned)~0 >> 1) + 1) / 10);    
    static const int MAX_R = (int)((unsigned)~0 >> 1) % 10;    
    static const int MIN_R = (int)((((unsigned)~0 >> 1) + 1) % 10);    
    int n = 0;    
    int sign = 1;    
    int c;    
    
    while (isspace(*str))    
        ++str;    
    if (*str == '+' || *str == '-')    
    {    
        if (*str == '-')    
            sign = -1;    
        ++str;    
    }    
    while (isdigit(*str))    
    {    
        c = *str - '0';    
        if (sign > 0 && (n > MAX_DIV || (n == MAX_DIV && c >= MAX_R)))    
        {    
            n = MAX;    
            break;    
        }    
        else if (sign < 0 && (n > MIN_DIV || (n == MIN_DIV && c >= MIN_R)))    
        {    
            n = MIN;    
            break;    
        }    
        n = n * 10 + c;    
        ++str;    
    }    
    return sign > 0 ? n : -n;    
}    