#include <stdio.h>
int main() 
{
	int a[1000][10];
	int i,j,x,sum=0;
	int k=0;
	scanf("%d",&x);
	for(i=1;i<=x;i++)
	{
		for(j=1;j<i;j++)
		{
			if(i%j==0)
			{
				sum=sum+j;
				a[i][k++]=j;
			}	
		}
		if(sum==i)
		{
			printf("%d its factors are %d",i,a[i]);
		}
		
	}
	return 0;
}
