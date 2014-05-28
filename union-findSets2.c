// Description

// Severe acute respiratory syndrome (SARS), an atypical pneumonia of unknown aetiology, was recognized as a global threat in mid-March 2003. To minimize transmission to others, the best strategy is to separate the suspects from others. 
// In the Not-Spreading-Your-Sickness University (NSYSU), there are many student groups. Students in the same group intercommunicate with each other frequently, and a student may join several groups. To prevent the possible transmissions of SARS, the NSYSU collects the member lists of all student groups, and makes the following rule in their standard operation procedure (SOP). 
// Once a member in a group is a suspect, all members in the group are suspects. 
// However, they find that it is not easy to identify all the suspects when a student is recognized as a suspect. Your job is to write a program which finds all the suspects.
// Input

// The input file contains several cases. Each test case begins with two integers n and m in a line, where n is the number of students, and m is the number of groups. You may assume that 0 < n <= 30000 and 0 <= m <= 500. Every student is numbered by a unique integer between 0 and n−1, and initially student 0 is recognized as a suspect in all the cases. This line is followed by m member lists of the groups, one line per group. Each line begins with an integer k by itself representing the number of members in the group. Following the number of members, there are k integers representing the students in this group. All the integers in a line are separated by at least one space. 
// A case with n = 0 and m = 0 indicates the end of the input, and need not be processed.
// Output

// For each case, output the number of suspects in one line.
// Sample Input

// 100 4
// 2 1 2
// 5 10 13 11 12 14
// 2 0 1
// 2 99 2
// 200 2
// 1 5
// 5 1 2 3 4 5
// 1 0
// 0 0
// Sample Output

// 4
// 1
// 1

#include<stdio.h>

int n, m, i, j;
int father[30005], num[30005];

//递归实现
void makeSet(int n){
    for(int i=0;i<n;i++) {
	   father[i] = i;
	   num[i] = 1;
	}
}

int findSet(int x){
    if(father[x] != x)
	   father[x] = findSet(father[x]);
	return father[x];

}

//非递归实现
void make_set(int n){
    for(int i=0;i<n;i++) {
	   father[i] = -1;
	   num[i] = 1;
	}
}

int find_set(int x){
    while(father[x] != -1)
	   x = father[x];
	return x;

}

void Union(int a, int b){
    int x = findSet(a);
	int y = findSet(b);
	if(x==y)
	   return;
	if(num[x]<=num[y]){
	   father[x] = y;
	   num[y]+=num[x];
	} 	
	else {
	   father[y] = x;
	   num[x]+=num[y];
	}
}

int main(){
    while(scanf("%d %d", &n, &m)!=EOF && n != 0) {
        makeSet(n);
        for(i = 0; i < m; i++) {
            int count, first, b;
            scanf("%d %d",&count, &first);
            for(j = 1; j < count; j++) {
                scanf("%d",&b);
                Union(first,b);
            }
        }
        printf("result=%d\n",num[findSet(0)]);
    }
    return 0;
}