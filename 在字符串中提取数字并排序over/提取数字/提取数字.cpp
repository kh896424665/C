#include<stdio.h>
#define N 100
int *paixu(int b[],int j)
{
	int *p=b;
	int i,k,t;
	for(i=0;i<j-1;i++)
		for(k=0;k<j-i;k++)
		{
			if(b[k]<b[k+1])
			{
				t=*(p+k);
				*(p+k)=*(p+k+1);
				*(p+k+1)=t;
			} 

		}
	return(p);
}



void main()
{
	char a[100];
	int b[100];
	int i,j=0,sum=0,*p;
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			sum=sum*10+(a[i]-'0');//将数字提取
			if(a[i+1]<='0'||a[i+1]>='9')
			{
				b[j]=sum;
				j++;
				sum=0;
			}
		}
		
	}
	if(a[i-1]<='9'&&a[i-1]>='0')
		b[j]=a[i-1];
	for(i=0;i<j;i++)
		printf("%d ",b[i]);
	p=paixu(b,j);
	printf("\n排序后：");
		for(i=0;i<j;i++)
		printf("%d ",*(p+i));
	getchar();
	
}