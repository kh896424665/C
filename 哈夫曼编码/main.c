#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node
{
	char data;	//结点值 
	int weight;		//权值 
	int parent,left,right;		//存放父节点及左右儿子结点的地址 
}node;
void hftree(char *v,int *w,int size,char *result) 
{
	#define max_int 32767
	int min1,min2;		//最小数/次小树的权值
	int x,y;			//最小树次小树的下标 
	int j;
	int p,s;
	//置初值
	int length=16;
	node elem[16] ;		//weizhichangdu
	int i;
	for(i=size;i<length;++i)
	{
		elem[i].weight=w[i-size];
		elem[i].data=v[i-size];
		elem[i].parent=elem[i].left=elem[i].right=0;
	}
	 //归并森林中的树
	 for(i=size-1;i>0;--i)
	 {
	 	min1=min2=max_int ;
	 	x=0;y=0;
	 			//
	 	for(j=i+1;j<length;++j)
	 	{
	 		if(elem[j].parent==0)
	 			if(elem[j].weight<min1)
	 				{min2=min1;min1=elem[j].weight;x=y;y=j;}
	 			else if(elem[j].weight<min2)
	 				{min2=elem[j].weight;x=j;}		//？？？
			elem[i].weight=min1+min2;
			elem[i].left=x;
			elem[i].right=y;
			elem[i].parent=0;
			elem[x].parent=i;elem[y].parent=i; 
	 	}
	 } 
	 	//s记录当前处理的结点，p记录s的父节点下标
	 for(i=size;i<length;i++)
	 {
	 	//result[i-size]='';
	 	p=elem[i].parent;
	 	s=i;
	 	while(p)
	 	{
	 		if(elem[p].left==s)
	 			strcat("0",result[i-size]);
			 else
			 	strcat("1",result[i-size]);
			s=p;p=elem[p].parent; 
	 		
		} 
	 
	} 
}
int main()
{
	char v[100];
	int w[100];
	int size,i;
	char result[100][100];
	printf("请输入待编码元素的个数：");
	scanf("%d",&size);
	printf("\n");
	printf("请输入待编码：");
	gets(v);
	/*for(i=0;i<=size;i++)
	{
		scanf("%c",&v[i]);
	}*/
	printf("依次输入权值：");
	for(i=0;i<size;i++)
	scanf("&d",&w[i]);
]	hftree(v,w,size,result);
	printf("第几个编码：");
	scanf("&d",&i);
	puts(result[i]); 
}
