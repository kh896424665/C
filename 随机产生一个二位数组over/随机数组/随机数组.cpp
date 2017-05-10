#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int a[3][4],b[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int m,i,j,l=12;
	srand((unsigned int)time(NULL));
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			m=rand()%l;
			a[i][j]=b[m];
			for(;m<l;m++)//将b数组移动一个，避免重复
			{
				b[m]=b[m+1];
			}
			l--;
		}
		
	}
	for(i=0;i<3;i++)
	{

		for(j=0;j<4;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	
	getchar();
	return 0;
	
}