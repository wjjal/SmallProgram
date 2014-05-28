//字符串匹配问题，给定一串字符串，按照指定规则对其进行匹配，并将匹配的结果保存至output数组中，多个匹配项用空格间隔，最后一个不需要空格。
//要求：
//匹配规则中包含通配符？和*，其中？表示匹配任意一个字符，*表示匹配任意多个（>=0）字符。
//匹配规则要求匹配最大的字符子串，例如a*d,匹配abbdd而非abbd,即最大匹配子串。
//匹配后的输入串不再进行匹配，从当前匹配后的字符串重新匹配其他字符串。

#include <stdio.h>
#include<stdlib.h>

char *my_find(char  input[],   char rule[]);

void main(){
   char input[20];
   char rule[10];
   char* output;
   printf("Please input the string:");
   scanf("%s",input);
   printf("Please input the rule:");
   scanf("%s",rule);
   output = my_find(input,rule);
   printf("output=%s",output);
}

int str_len(char *a) {  //字符串长度  
    if (a == 0) {  
        return 0;  
    }  
    char *t = a;  
    for (;*t;++t)  
        ;  
    return (int) (t - a);  
}  
  
void str_copy(char *a,const char *b,int len) {  //拷贝字符串 a = b  
    for (;len > 0; --len, ++b,++a) {  
        *a = *b;  
    }  
    *a = 0;  
}  
  
char *str_join(char *a,const char *b,int lenb) { //连接字符串 第一个字符串被回收  
    char *t;  
    if (a == 0) {  
        t = (char *) malloc(sizeof(char) * (lenb + 1));   
        str_copy(t, b, lenb);  
        return t;  
    }  
    else {  
        int lena = str_len(a);  
        t = (char *) malloc(sizeof(char) * (lena + lenb + 2));  
        str_copy(t, a, lena);  
        *(t + lena) = ' ';  
        str_copy(t + lena + 1, b, lenb);  
        free(a);  
        return t;  
    }  
}  
  
int canMatch(char *input, char *rule) { // 返回最长匹配长度 -1表示不匹配　  
    if (*rule == 0) { //已经到rule尾端  
        return 0;  
    }  
    int r = -1 ,may;  
    if (*rule == '*') {  
        r = canMatch(input, rule + 1);  // *匹配0个字符  
        if (*input) {  
            may = canMatch(input + 1, rule);  // *匹配非0个字符			
            if ((may >= 0) && (++may > r)) {
                r = may;  
            }  
        }  
    }  
    if (*input == 0) {  //到尾端  
        return r;  
    }  
    if ((*rule == '?') || (*rule == *input)) {  
        may = canMatch(input + 1, rule + 1);  
        if ((may >= 0) && (++may > r)) {  
            r = may;  
        }  
    }  
    return r;  
}  
  
char *my_find(char  input[],   char rule[]) {  
    int len = str_len(input);  
    int *match = (int *) malloc(sizeof(int) * len);  //input第i位最多能匹配多少位 匹配不上是-1  
    int i,max_pos = - 1;  
    char *output = 0;  
  
    for (i = 0; i < len; ++i) {  
        match[i] = canMatch(input + i, rule);		
        if ((max_pos < 0) || (match[i] > match[max_pos])) {  
            max_pos = i;  
        }  
    }  
    if ((max_pos < 0) || (match[max_pos] <= 0)) {  //不匹配  
        output = (char *) malloc(sizeof(char));  
        *output = 0;   // \0  
        return output;  
    }  
    for (i = 0; i < len;) {  
        if (match[i] == match[max_pos]) { //找到匹配  
            output = str_join(output, input + i, match[i]);  
            i += match[i];  
        }  
        else {  
            ++i;  
        }  
    }  
    free(match);  
    return output;  
}  