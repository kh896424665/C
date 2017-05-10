#include <stdio.h>
#define N 1000
int main()
{
	int n,i,k;
	int a[N];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n-1;i++)
	{
		a[i]=abs(a[i+1]-a[i]);
	}
	k=a[0];
	for(i=1;i<n-1;i++)
	{
		if(k<a[i])
			k=a[i];
	}
	printf("%d",k);
	return 0; 
} 
