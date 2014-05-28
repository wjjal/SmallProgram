//题目描述：求最长不重复子串，如abcdefgegcsgcasse，最长不重复子串为abcdefg，长度为7#include<stdio.h>

//思路：用一个数组保存字符出现的次数。用i和j进行遍历整个字符串。
//当某个字符没有出现过，次数+1；出现字符已经出现过，次数+1，找到这个字符前面出现的位置的下一个位置，设为i
//并将之前的那些字符次数都-1。继续遍历，直到'\0'

#include<stdio.h>

int find(char str[],char *output)
{
	int i = 0 , j = 0;
	int cnt[26] = {0};
	int res = 0 , temp = 0;
	char *out = output;
	int final;
	while(str[j] != '\0')
	{
		if(cnt[str[j]-'a'] == 0)
		{
			cnt[str[j]-'a']++;

		}
		else
		{
			cnt[str[j]-'a']++;
			while(str[i] != str[j])
			{	
				cnt[str[i]-'a']--;
				i++;
			}
			cnt[str[i]-'a']--;
			i++;
		}	

		j++;
		temp = j-i;
		if(temp > res)
		{
			res = temp;
			final = i;
		}
	}
	//结果保存在output里面
	for(i = 0 ; i < res ; ++i)
		*out++ = str[final++];
	*out = '\0';
	return res;
}
int main(void)
{
	char a[] = "abcdefg";
	char b[100];
	int max = find(a,b);
	printf("%s\n",b);
	printf("length=%d",max);
	return 0;
}