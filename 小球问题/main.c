#include<stdio.h>
int main()
{
	float m,s;
	int n,i;
	scanf("%f%d",&m,&n);
	s=m;
	for(i=1;i<=n;i++)
	{
		m=m/2;
		s=s+2*m;
	}
	s=s-m*2;
	printf("%.2f %.2f",m,s);
	return 0;
	
}
