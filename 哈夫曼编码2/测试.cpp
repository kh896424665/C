#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define length sizeof(htnode)
typedef struct htnode
{
	char data;
	int weight;
	int parent,lchild,rchild;
}htnode,*huffmantree;		//�������洢�ṹ 
typedef char **huffmancode;		//�洢�����������
void huffmancoding(huffmantree ht,huffmancode &hc,int *w,char *v,int n)//v�Ǵ�����Ԫ�����飬w��ÿ��Ԫ�ص�Ȩֵ�������������ht��hc��Ź��������� 
{	
	int i,m,s1,s2,min1,min2,j;
	char *cd;
	int start,c,f;
	if(n<=1) return;
	m=2*n-1;
	ht=(huffmantree)malloc((m+1)*length);	//��n��Ҷ�ӽڵ��hfuumantree��Ҫ2n-1�����洢 
	for(i=1;i<=n;++i,++w,++v)	//��n��Ԫ�ؽ���ֵ��Ȩֵ���������Һ��ӱ��Ϊ0 
	{
		ht[i].data=*v;ht[i].weight=*w;ht[i].lchild=0;ht[i].parent=0;ht[i].rchild=0; 
	}
	for(;i<=m;++i)	//�Ժ�m-n����Ҷ�ӽڵ��� 
	{
			ht[i].data=0;ht[i].weight=0;ht[i].lchild=0;ht[i].parent=0;ht[i].rchild=0 ;
	}
	for(i=n+1;i<=m;++i)	//����
	{
		 s1=s2=0;min1=min2=32767;
		 for(j=1;j<=i-1;++j)
		 {
		 	if(ht[j].parent==0)
			{if(ht[j].weight<min1)
			{min2=min1;min1=ht[j].weight;s2=s1;s1=j;}	//�˵�һ�δ��������
		 			else if(ht[j].weight<min2)
					{min2=ht[j].weight;s2=j;}}
		 }
		 ht[s1].parent=i;ht[s2].parent=i;
		 ht[i].lchild=s1;ht[i].rchild=s2;
		 ht[i].weight=min1+min2;
	}	 
	//һ��Ϊ��Ҷ�ӽ�㵽���ڵ������������ 
	hc=(huffmancode)malloc((n+1)*sizeof(char *));	//����n���ַ������ͷָ������ 
	cd=(char*)malloc(n*sizeof(char)); 	//���������Ĺ����ռ� 
	cd[n-1]='\0';
	for(i=1;i<=n;++i)
	{
		start=n-1;
		for(c=i,f=ht[i].parent;f!=0;c=f,f=ht[f].parent)	//Ҷ�ӵ���
		{
			if(ht[f].lchild==c) //////=======
				cd[--start]='0';
			else
				cd[--start]='1';
		} 
		hc[i]=(char *)malloc((n-start)*sizeof(char));	//Ϊ��i���ַ��������ռ�
		strcpy(hc[i],cd+start); 
	} 
	free(cd);
}  //huffmancoding
void main()
{
	printf("**********����������***********  by-KangHui\n");
	int n,i;
	char *v;	//���ַ� 
	int *w;	//Ȩֵ 
	huffmantree ht;
	huffmancode hc;
	printf("��������Ҫ����Ԫ�صĸ���:");
	scanf("%d",&n);
	printf("������Ҫ������ַ���(�������벻Ҫ�пո�:)") ;
	v=(char *)malloc((n+2)*sizeof(char)) ;
	v[n+1]='\0';
	scanf("%s",v);
	w=(int *)malloc((n+1)*sizeof(int));
	printf("������ÿ���ַ���Ȩֵ(�ո����):");
	for(i=0;i<n;++i)		//i=1���󣬿��ܻ���ɴ����ȥ�βο�ִ��
	{
		scanf("%d",w+i);
	} 
	huffmancoding(ht,hc,w,v,n);
	printf("�����ַ�����������ֱ�Ϊ:");
	for(i=1;i<=n;i++)
	printf("%s  ",hc[i]);   ///���ﾹȻ����һֱ�õ�ht������������ô��= =
	printf("\n");
	
}
