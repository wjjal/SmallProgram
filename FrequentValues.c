//RMQ问题 
//http://blog.163.com/zhaohai_1988/blog/static/209510085201263011135062/

/* Description
You are given a sequence of n integers a1 , a2 , ... , an in non-decreasing order. In addition to that, you are given several queries consisting of indices i and j (1 ≤ i ≤ j ≤ n). For each query, determine the most frequent value among the integers ai , ... , aj.

Input
The input consists of several test cases. Each test case starts with a line containing two integers n and q (1 ≤ n, q ≤ 100000). The next line contains n integers a1 , ... , an (-100000 ≤ ai ≤ 100000, for each i ∈ {1, ..., n}) separated by spaces. You can assume that for each i ∈ {1, ..., n-1}: ai ≤ ai+1. The following q lines contain one query each, consisting of two integers i and j (1 ≤ i ≤ j ≤ n), which indicate the boundary indices for the query.

The last test case is followed by a line containing a single 0.

Output
For each query, print one line with one integer: The number of occurrences of the most frequent value within the given range.

Sample Input
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
0
Sample Output
1
4
3 */

#include<stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MAXN 1000010
int a[MAXN];
int m[MAXN][20];     //m[i][j] 表示在区间[i, i+(1<<j)-1]内的元素中出现次数最多元素的出现次数（当然并不是都在这个区间内，只要相同的元素有一个在区间内就计算）
int numEqualL[MAXN]; //当前位置及以左边等于该元素的个数
int numEqualR[MAXN]; //当前位置及以右边等于该元素的个数
void RMQInit(int n)
{
	int i, j;
	for(i = 1; i <= n; i++)
		m[i][0] = numEqualL[i] + numEqualR[i] - 1;
	for(j = 1; (1<<j) <= n; j++)
		for(i = 1;i+(1<<j)-1 <= n; i++)
			m[i][j] = MAX(m[i][j-1], m[i+(1<<(j-1))][j-1]);
}
int RMQ(int l, int r)
{
	int x = MIN(numEqualR[l], r-l+1);  // 左端元素区间内出现的次数
	int y = MIN(numEqualL[r], r-l+1);  // 右端元素区间内出现的次数
	// printf("%d,%d\n",x,y);
	l += x;  // 调整区间大小，使区间内出现的元素都在区间内
	r -= y;
	if(r < l) return MAX(x, y);
	int t = r-l+1;
	int k = 0;
	while(t > 1){t >>= 1; k++;}//k=[log2(j-i+1)]
	return MAX(MAX(x, y), MAX(m[l][k], m[r-(1<<k)+1][k]));
}
void main()
{
	int n, q, i;
	printf("Please intput the number of array and the query:\n");
	scanf("%d%d",&n,&q);
	printf("Please intput the array:\n");
	for(int i = 1;i <= n; i++){//输入数组下标从1开始
	   scanf("%d",&a[i]);
	   numEqualL[i] = 1;
	   numEqualR[i] = 1;
	}
	for(i = 2;i <= n; i++)
	    if(a[i] == a[i-1])
		   numEqualL[i] += numEqualL[i-1];
	for(i = n-1; i > 0; i--) 
		if(a[i] == a[i+1])
	      numEqualR[i] += numEqualR[i+1];
	RMQInit(n);
	// for(int i =1;i<n;i++){
	   // printf("%d,%d\n",numEqualL[i],numEqualR[i]);
	// }
	int l, r;
	printf("Please intput the query:\n");
	for(int i = 0;i <  q; i++){
	   scanf("%d%d", &l, &r);
	   printf("result = %d\n",RMQ(l, r));
	}
}