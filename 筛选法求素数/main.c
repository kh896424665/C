#include<stdio.h>
#define N 1000
int main()
{
	int a[N];
	int num,i,j;
	scanf("%d",&num);
	for(i=2;i<=num;i++)
	{
		a[i]=i;
	}
	for(i=3;i<=num;i++)
	{
		for(j=2;j<i;j++)
		if(i%j==0)	
			{
			a[i]=0;
			break;
			}
		
	}
	for(i=2;i<=num;i++)
	{
		if(a[i]!=0)
		printf("%d\n",a[i]);
	}
	
}
