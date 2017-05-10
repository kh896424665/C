#include<stdio.h>
int main()
{
	int i,j,s,r,t;
	int a[10];
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<10;i++)
	{
		s=a[i];
		for(j=i+1;j<10;j++)
		{
			if(s>a[j])
			{s=a[j];r=j;}
		}
		if(s!=a[i])
		{
			t=a[i];
			a[i]=s;
			a[r]=t;
		}
	}
	for(i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
	
}
