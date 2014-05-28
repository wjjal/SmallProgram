//并查集
// Description

// There are so many different religions in the world today that it is difficult to keep track of them all. You are interested in finding out how many different religions students in your university believe in. 

// You know that there are n students in your university (0 < n <= 50000). It is infeasible for you to ask every student their religious beliefs. Furthermore, many students are not comfortable expressing their beliefs. One way to avoid these problems is to ask m (0 <= m <= n(n-1)/2) pairs of students and ask them whether they believe in the same religion (e.g. they may know if they both attend the same church). From this data, you may not know what each person believes in, but you can get an idea of the upper bound of how many different religions can be possibly represented on campus. You may assume that each student subscribes to at most one religion.

// Input

// The input consists of a number of cases. Each case starts with a line specifying the integers n and m. The next m lines each consists of two integers i and j, specifying that students i and j believe in the same religion. The students are numbered 1 to n. The end of input is specified by a line in which n = m = 0.

// Output

// For each test case, print on a single line the case number (starting with 1) followed by the maximum number of different religions that the students in the university believe in.

// Sample Input
// 10 9
// 1 2
// 1 3
// 1 4
// 1 5
// 1 6
// 1 7
// 1 8
// 1 9
// 1 10
// 10 4
// 2 3
// 4 5
// 4 8
// 5 8
// 0 0

// Sample Output

// Case 1: 1
// Case 2: 7

#include<stdio.h>


int n, m, maxNum, i;
int father[50005], num[50005];

void makeSet(int n){
    for(int j=1;j<=n;j++) {
	   father[j] = j;
	   num[j] = 1;
	}
}

int findSet(int x){
    if(father[x] != x)
	   father[x] = findSet(father[x]);
	return father[x];
}

void Union(int a, int b){
    int x = findSet(a);
	int y = findSet(b);
	if(x==y)
	   return;
	if(num[x]<=num[y]){
	   father[x] = y;
	   num[y]+=num[x];
	   maxNum--;
	} 	
	else {
	   father[y] = x;
	   num[x]+=num[y];
	   maxNum--;
	}
}

int main() {
   int Case = 1;
   while(scanf("%d %d", &n, &m)!=EOF && n!=0) {
        maxNum = n;
        makeSet(n);
        int a, b;
        for(i = 0; i < m; i++) {
            scanf("%d %d",&a, &b);
            Union(a,b);
        }
        printf("Case %d: %d\n",Case++,maxNum);
    }
    return 0;
}