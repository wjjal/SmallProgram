/* Beijing was once surrounded by four rings of city walls: the Forbidden City Wall, the Imperial City Wall, the Inner City Wall, and finally the Outer City Wall. Most of these walls were demolished in the 50s and 60s to make way for roads. The walls were protected by guard towers, and there was a guard living in each tower. The wall can be considered to be a large ring, where every guard tower has exaetly two neighbors.

The guard had to keep an eye on his section of the wall all day, so he had to stay in the tower. This is a very boring job, thus it is important to keep the guards motivated. The best way to motivate a guard is to give him lots of awards. There are several different types of awards that can be given: the Distinguished Service Award, the Nicest Uniform Award, the Master Guard Award, the Superior Eyesight Award, etc. The Central Department of City Guards deterMINed how many awards have to be given to each of the guards. An award can be given to more than one guard. However, you have to pay attention to one thing: you should not give the same award to two neighbors, since a guard cannot be proud of his award if his neighbor already has this award. The task is to write a program that deterMINes how many different types of awards are required to keep all the guards motivated.

题目大意：有n个人为成一个圈，其中第i个人想要r[i]种不同的礼物，相邻的两个人可以聊天，炫耀自己的礼物。如果两个相邻的人拥有同一种礼物，则双方都会很不高兴，问最少需要多少种不同的礼物才能满足所有人的需求，假设每种礼物有无限多个。

Input 

The input contains several blocks of test eases. Each case begins with a line containing a single integer l$ \le$n$ \le$100000, the number of guard towers. The next n lines correspond to the n guards: each line contains an integer, the number of awards the guard requires. Each guard requires at least 1, and at most l00000 awards. Guard i and i + 1 are neighbors, they cannot receive the same award. The first guard and the last guard are also neighbors.

The input is terMINated by a block with n = 0.

Output 

For each test case, you have to output a line containing a single integer, the MINimum number x of award types that allows us to motivate the guards. That is, if we have x types of awards, then we can give as many awards to each guard as he requires, and we can do it in such a way that the same type of award is not given to neighboring guards. A guard can receive only one award from each type.

Sample Input 

3
4
2
2
5
2
2
2
2
2
5
1
1
1
1
1
0
Sample Output 

8
5
3 */


// 思路：如果n为偶数的话，ans = MAX{r[i] + r[i + 1] },(r[n + 1] = r[1]).
//如果n为奇数的话，上述式子就不成立了，因为n个人围成圈的话，头尾两人是相邻的，但他们都是奇数位置的人，不能满足奇数尽量取前，偶数尽量取后。所以要用到二分的方法搜索答案///，但最关键的是怎么判断说一个值是否可以满足条件。
// 这里用到了一个很巧妙的方法，就是将1~tmp分成1~r[i], r[i] + 1 ~ tmp, //两个区间，然后奇数尽量去前面区间编号的礼物，偶数的尽量取后面区间编号的礼物，这样计算到第n个人，如果他没有取前一个区间的礼物，即为满足条件。

#include <stdio.h>
#include <string.h>

#define N 10005
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

int n, r[N], right[N], left[N];

void init() {
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= n; i++)	
	   scanf("%d", &r[i]);
	r[n + 1] = r[1];
}

int test(int tmp) {
	int x = r[1], y = tmp - r[1];
	//left为取的前面区间的数量，right为取的后面区间的数量
	left[1] = x, right[1] = 0;
	printf("%d\n",tmp);
	for (int i = 2; i <= n; i++) {
		if (i & 1) {  // 第奇数个,尽量往后取  
			right[i] = MIN(y - right[i - 1], r[i]);
			left[i] = r[i] - right[i];
		} else {   //第偶数个，尽量往前取 
			left[i] = MIN(x - left[i - 1], r[i]);
			right[i] = r[i] - left[i];
		}
		printf("%d,%d\n",left[i],right[i]);
	}
	return left[n];
}

int solve() {
	if (n == 1) return r[1];
	
	int L = 0, R = 0;
    
	//偶数个直接返回L
	for (int i = 1; i <= n; i++) 
	    L = MAX(L, r[i] + r[i + 1]);
    
	//若为奇数个
	if (n & 1) {
		for (int i = 1; i <= n; i++) 
		   R = MAX(R, r[i] * 3);

		while (L < R) {
			int M = (L + R) / 2;
			if (test(M) == 0) 
			   R = M;
			else L = M + 1;
		}
	}

	return L;
}

int main () {
	while (scanf("%d", &n) == 1 && n) {
		init();
		printf("%d\n", solve());
	}
	return 0;
}
