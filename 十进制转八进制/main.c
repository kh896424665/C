#include<stdio.h>
int main()
{
	int n,i=0;
	int a[20];
	scanf("%d",&n);
	while(n/8!=0)
	{
		a[i]=n%8;
		n=n/8;
		i++;
	}
	a[i]=n%8;
	while(i>=0)
	{
		printf("%d",a[i]);
		i--;
		
	}
} 
