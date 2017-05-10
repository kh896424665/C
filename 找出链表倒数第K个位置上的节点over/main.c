#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct arr)
struct arr            //结点类型 
{
	char data;
	struct arr *next;
};
int n;
struct arr *creat(void)		//创建链表函数 
{
	struct arr *head,*p1,*p2;
	n=0;
	p1=p2=(struct arr*)malloc(LEN);
	scanf("%c",&p1->data);
	head=NULL;
	while(p1->data!='\n')				//当输入回车时循环结束 
	{
		n=n+1;
		if(1==n)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct arr*)malloc(LEN);
		scanf("%c",&p1->data);
	
	}
	p2->next=NULL;
	return head;
} 
int locate(struct arr *list,int k)		//定位函数 
{
	struct arr *p1,*p2;
	int i;
	p1=list;
	p2=list;
	for(i=1;i<=k;i++)
	{
		if(p1->next==NULL) 
		return 0;					//长度小于K，返回0 
		p1=p1->next;
	}
	while(p1)
	{
		p2=p2->next;
		p1=p1->next;
	}
	printf("%c",p2->data);
	return 1;
}
int main()
{
	int k,y;
	struct arr *list;
	printf("请输入链表内容（字符串）:") ; 
	list=creat();
	printf("要找倒数第几个节点：");
	scanf("%d",&k); 
	printf("倒数第K个结点是:");
	y=locate(list,k);
	if(0==y)	printf("链表长度小于k！"); 
	getchar();
	return 0;
	 
}
