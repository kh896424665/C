#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct node
{
	char data;	//���ֵ 
	int weight;		//Ȩֵ 
	int parent,left,right;		//��Ÿ��ڵ㼰���Ҷ��ӽ��ĵ�ַ 
}node;
void hftree(char *v,int *w,int size,char *result) 
{
	#define max_int 32767
	int min1,min2;		//��С��/��С����Ȩֵ
	int x,y;			//��С����С�����±� 
	int j;
	int p,s;
	//�ó�ֵ
	int length=16;
	node elem[16] ;		//weizhichangdu
	int i;
	for(i=size;i<length;++i)
	{
		elem[i].weight=w[i-size];
		elem[i].data=v[i-size];
		elem[i].parent=elem[i].left=elem[i].right=0;
	}
	 //�鲢ɭ���е���
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
	 				{min2=elem[j].weight;x=j;}		//������
			elem[i].weight=min1+min2;
			elem[i].left=x;
			elem[i].right=y;
			elem[i].parent=0;
			elem[x].parent=i;elem[y].parent=i; 
	 	}
	 } 
	 	//s��¼��ǰ����Ľ�㣬p��¼s�ĸ��ڵ��±�
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
	printf("�����������Ԫ�صĸ�����");
	scanf("%d",&size);
	printf("\n");
	printf("����������룺");
	gets(v);
	/*for(i=0;i<=size;i++)
	{
		scanf("%c",&v[i]);
	}*/
	printf("��������Ȩֵ��");
	for(i=0;i<size;i++)
	scanf("&d",&w[i]);
]	hftree(v,w,size,result);
	printf("�ڼ������룺");
	scanf("&d",&i);
	puts(result[i]); 
}
