//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，则删除之后的第一个字符串变成”Thy r stdnts.”
#include <stdio.h>

void DeleteChars(char str[],int hashtable[]);

void main(){
   char input[100];
   int deleted[256];
   char c;
   printf("Please input the string:");
   scanf("%s",input);
   printf("Please input the deletedchar:");
   getchar();
   while((c=getchar())!='\n'){
      deleted[c] = 1;
   }
   DeleteChars(input,deleted);   
   int i = 0;
   while(input[i]!='\0'){
	 printf("%c",input[i++]);     	 
   }
}

void DeleteChars(char str[],int hashtable[]){
    int i = 0,j = i;
	while(str[j]!='\0'){
	   if(hashtable[str[j]]!=1){
	      str[i] = str[j];
		  i++;
	   }
	   j++;
	}
	str[i] = '\0';
}