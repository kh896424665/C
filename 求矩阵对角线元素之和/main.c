#include <stdio.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	int a[3][3];
	int i,j,sum1=0,sum2=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		scanf("%d",&a[i][j]);	
		}
		
	}
	for(i=0;i<3;i++)
	{
		sum1=sum1+a[i][i];
		sum2=sum2+a[i][2-i];
	}
	printf("%d %d ",sum1,sum2);
	return 0;
}
