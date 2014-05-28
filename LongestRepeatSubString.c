// 问题描述
// 给定一个字符串，求出其最长重复子串
// 例如：abcdabcd
// 最长重复子串是 abcd，最长重复子串可以重叠
// 例如：abcdabcda，这时最长重复子串是 abcda，中间的 a 是被重叠的。

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 5000 //最长处理5000个字符

char c[MAXCHAR], *a[MAXCHAR];

int comlen( char *p, char *q )
{
    int i = 0;
    while( *p && (*p++ == *q++) )
        ++i;
    return i;
}

int pstrcmp( const void *p1, const void *p2 )
{
    return strcmp( *(char* const *)p1, *(char* const*)p2 );
}


int main(void)
{
    char ch;
    int  n=0;
    int  i, temp;
    int  maxlen=0, maxi=0;
    printf("Please input your string:\n");
	n = 0;
    while( (ch=getchar())!='\n' )
	{
        a[n] = &c[n];
        c[n++] = ch;
		
    }
	
    c[n]='\0';     // 将数组c中的最后一个元素设为空字符，以终止所有字符串
	
    qsort( a, n, sizeof(char*), pstrcmp );
    for(i = 0 ; i < n-1 ; ++i )
	{
        temp=comlen( a[i], a[i+1] );
        if( temp>maxlen )
		{
            maxlen=temp;
            maxi=i;
        }
    }
	//printf("%s\n",a[maxi]);
    printf("%.*s\n",maxlen, a[maxi]);
    
    return 0;
}