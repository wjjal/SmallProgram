//把n个骰子扔在地上，所有骰子朝上一面的点数之和为S。输入n，打印出S的所有可能的值出现的概率。
#include<stdio.h>
#include<math.h>
#define MAX_VALUE 6

void PrintSumProbabilityOfDices_2(int number);

void main(){
   int number;
   printf("Please input the number of dice:\n");
   scanf("%d",&number);
   PrintSumProbabilityOfDices_2(number);
}

void PrintSumProbabilityOfDices_2(int number){
   double Probabilities[2][MAX_VALUE * number + 1];
   for(int i=1;i<MAX_VALUE*number+1;i++){
      Probabilities[0][i] = 0;
	  Probabilities[1][i] = 0;
   }
   int flag = 0;
   for(int i=1; i<=MAX_VALUE; ++i)
      Probabilities[flag][i] = 1;
   for(int i=2;i<=number;i++){
      for(int j=i;j<=MAX_VALUE*i;j++){
         Probabilities[1 - flag][j] = 0;
		 for(int k = 1;k<j && k<=MAX_VALUE;k++)
		 Probabilities[1 - flag][j] += Probabilities[flag][j-k];
      }
      flag = 1-flag;	  
   }
	double total = pow((double)MAX_VALUE, number);
	printf("total=%f\n",total);
    for(int i = number; i <=MAX_VALUE * number; ++i)
    {
        double ratio = Probabilities[flag][i] / total;
        printf("%d:%f,%f\n", i,Probabilities[flag][i], ratio);
    }
}