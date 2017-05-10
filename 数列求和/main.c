#include <stdio.h>
int main()
{
	float m,n,s=0,r;
	int i,t;
	scanf("%d",&t);
	m=1;n=2;
	for(i=1;i<=t;i++)
	{
		s=s+n/m;
		r=m;
		m=n;
		n=r+n;
	}
	printf("%.2f",s);
	
} 
