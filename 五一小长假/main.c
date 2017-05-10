#include<stdio.h> 
#define N 1000 
int main()
{
	int m,n,i,sum=0;
	int a[N];
	scanf("%d %d",&m,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(m>0)
		{
			sum++;
			m=m-a[i];
		}
		else
		break;
	}
	printf("%d",sum);
	
	
}
