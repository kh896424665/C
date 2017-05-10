#include<stdio.h>
#define N 20
int listinsert(int *l,int i,int e,int len)
{
	int k;
	if(i<1||i>len+1)
		return 0;
	else
	{
		for(k=len-1;k>=i-1;k--)
		{
		   *(l+k+1)=*(l+k);
		}
		*(l+i-1)=e;
		return 1;
	}
}
int main()
{
	int a[N]={1,2,3,4,5,7,8,9};
	int *l=a;
	int i,len=8,e,j,s;
	for(i=0;i<len;i++)
		printf("%d ",a[i]);
	printf("\n请补全数字1-9!\n应该补数字:");
	scanf("%d",&e);
	printf("应该插入到第几个位置：");
	scanf("%d",&j);
	s=listinsert(l,j,e,len);
	if(s==0)
		printf("输入错误");
	else
		for(i=0;i<=len;i++)
			printf("%d ",a[i]);
	getchar();
	return 1;	
}
