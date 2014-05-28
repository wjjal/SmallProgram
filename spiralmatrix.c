//打印螺旋矩阵

#include<stdio.h>

#define rows 3
#define columns 3

int matrix[rows][columns];
void print(int matrix[rows][columns]);

void main(){
    int num = 1;
    for(int i=0;i<rows;i++){
	   for(int j=0;j<columns;j++){
	      matrix[i][j] = num++; 
	   }
	}
	print(matrix);
}

void print(int matrix[rows][columns]){
    int beginX = 0;
	int beginY = 0;
	int endX = columns - 1;
	int endY = rows - 1;
	int x = beginX;
	int j = beginY;
    while(1){
	  for(int i = beginX; i <= endX; i++)
	     printf("%d ",matrix[beginY][i]);
	  if(++beginY > endY)
	     break;
	  for(int i = beginY; i <= endY; i++)
	     printf("%d ",matrix[i][endX]);
	  if(beginX > --endX)
	     break;
	  for(int i = endX; i >= beginX; i--)
	     printf("%d ",matrix[endY][i]);
	  if(beginY > --endY)
	     break;
	  for(int i = endY; i >= beginY; i--)
	     printf("%d ",matrix[i][beginX]);
	  if(++beginX > endX)
	     break;
	}
}