//Description

//Given a sequence of positive integers, count all contiguous subsequences (sometimes called substrings, in contrast to subsequences, which may leave out elements) //the sum of which is divisible by a given number. These subsequences may overlap. For example, the sequence (see sample input) 
// 2, 1, 2, 1, 1, 2, 1, 2 contains six contiguous subsequences the sum of which is divisible(整除) by four: the first to eighth number, the second to fourth number, the //second to seventh number, the third to fifth number, the fourth to sixth number, and the fifth to seventh number.

// Input
// The first line of the input consists of an integer c (1 <= c <= 200), the number of test cases. Then follow two lines per test case. 
// Each test case starts with a line consisting of two integers d (1 <= d <= 1 000 000) and n (1 <= n <= 50 000), the divisor of the sum of the subsequences and the //length of the sequence, respectively. The second line of a test case contains the elements of the sequence, which are integers between 1 and 1 000 000 000, //inclusively.

// Output
// For each test case, print a single line consisting of a single integer, the number of contiguous subsequences the sum of which is divisible by d.

// Sample Input
//2
//7 3
//1 2 3
//4 8
//2 1 2 1 1 2 1 2

//Sample Output
//0
//6

//先求累加和sum[i](a[0]+a[1]+...+a[i])，然后求余，若两个累加和sum[i]%d==sum[j]%d，那么(sum[j]-sum[i])%d==0，即a[i+1], ... , //a[j]就是一个满足条件的连续子序列。注意余数为0的情况，可以在原序列最前面加上一个假设的元素0，这就就可以统一处理了。

//only support one testcase
#include<stdio.h>
#include<string.h>
#define MAX_LEN 50010
#define MAX_NUMBER 1000010

int sum[MAX_LEN];
long long int mod[MAX_NUMBER];

int main()
{
	int d,n;
	printf("Please input the divisor and the length of the array:\n");
	scanf("%d%d",&d,&n);
	int x;
	memset(mod, 0, sizeof(mod));
	sum[0]=0;
	//如果mod=0的仅有一组，就构成一个满足条件的result，而mod!=0时，至少需要两组才能构成一个result
	//初始化mod[0]=1,那么若有一组子序列整除d,则mod[0]=2，此时result+1,反之，若不置初始mod[0]=1，那么需要额外处理mod[0]
	mod[0]=1;
	printf("Please input the array:\n");
	for(int i = 1;i<=n;i++){
	   scanf("%d",&x);
	   sum[i]=sum[i-1]+x;
	   sum[i]%=d;
	   mod[sum[i]]++;
	}
	long long int result = 0;
	for(int i = 0;i<d;i++){
	    printf("%d,%d\n",i,mod[i]);
	    if(mod[i] > 0)
		   result += mod[i] * (mod[i]-1) / 2;
		   }
	printf("result = %lld",result);
}