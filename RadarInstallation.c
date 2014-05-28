/* Description

Assume the coasting is an infinite straight line. Land is in one side of coasting, sea in the other. Each small island is a point locating in the sea side. And any radar installation, locating on the coasting, can only cover d distance, so an island in the sea can be covered by a radius installation, if the distance between them is at most d. 

We use Cartesian coordinate system, defining the coasting is the x-axis. The sea side is above x-axis, and the land side below. Given the position of each island in the sea, and given the distance of the coverage of the radar installation, your task is to write a program to find the minimal number of radar installations to cover all the islands. Note that the position of an island is represented by its x-y coordinates. 
  
Figure A Sample Input of Radar Installations


Input

The input consists of several test cases. The first line of each case contains two integers n (1<=n<=1000) and d, where n is the number of islands in the sea and d is the distance of coverage of the radar installation. This is followed by n lines each containing two integers representing the coordinate of the position of each island. Then a blank line follows to separate the cases. 

The input is terminated by a line containing pair of zeros 
Output

For each test case output one line consisting of the test case number followed by the minimal number of radar installations needed. "-1" installation means no solution for that case.
Sample Input

3 2
1 2
-3 1
2 1

1 2
0 2

0 0
Sample Output

Case 1: 2
Case 2: 1 */

//求每个岛对应的覆盖它的雷达的有效区间，然后扫描区间去掉重合的。
//only one testcase
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

typedef struct Island
{
	int x; // 岛屿x坐标
	int y; // 岛屿y坐标
	double minRadarX; // 覆盖它的雷达有效区间的左端
	double maxRadarX; // 覆盖它的雷达有效区间的右端
} Island;

static int cmpIsland(const void *p1, const void *p2){
	/* The actual arguments to this function are "pointers to
	pointers to char", but strcmp(3) arguments are "pointers
	to char", hence the following cast plus dereference */
    return  ((Island *)p1)->x - ((Island *)p2)->x;
}

void main()
{
	int n, d;
	int caseNo = 0;
	printf("Please input the number of the island and the distance coverage of radar:\n");
	scanf("%d%d",&n,&d);
	if(n == 0 || d == 0) {
	   printf("Error!\n");
	   return;
	}
	Island islands[n];
	//Island *p = (Island *)malloc(n * sizeof(Island));
	printf("Please input the coordinate of the position of each island:\n");
	for(int i = 0;i<n;i++){
	   scanf("%d%d",&islands[i].x,&islands[i].y);
	   if(islands[i].y > d){
	      printf("Error!\n");
		  return;
	   }
	   islands[i].minRadarX = islands[i].x - sqrt(d * d * 1.0 - islands[i].y * islands[i].y);
	   islands[i].maxRadarX = islands[i].x + sqrt(d * d * 1.0 - islands[i].y * islands[i].y);
	}
	qsort(islands,n,sizeof(Island),cmpIsland);
    Island* p = islands;
	Island* end = p + n;
	double preEnd;
    int result = 0;
	bool first = true;
    printf("%d,%d",p,end);	
    while(p<end){
	   if(first){
	      result++;
	      preEnd = p->maxRadarX;
		  first = false;
	   }
	   if(p->minRadarX > preEnd){
	      result++;
	      preEnd = p->maxRadarX;
	   }
	   else {
	      preEnd = MIN(p->maxRadarX,preEnd);
	   }
	   p++;
    }
    printf("Result = %d",result);	
}