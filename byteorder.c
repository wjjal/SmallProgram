//测试计算机是大端还是小端
#include <stdio.h>

int main(){
	union {
		short s;
		char c[sizeof(short)];
	}un;
	un.s = 0x0102;
	//printf("%s",CPU_VENDOR_OS);
	if(sizeof(short) == 2){
		if(un.c[0]==1 && un.c[1]==2)
			printf("big-endina\n");
		else if (un.c[0]==2 && un.c[1]==1)
			printf("little-endina\n");
		else 
			printf("unknown");
	} else
		printf("sizeof(short)=%d\n",sizeof(short));
	//exit(0);
}
