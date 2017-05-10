#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(node)
typedef struct node
{
	char data;
	struct node *next;
} node,*log_node;
node *creat(void)
{
	log_node p1,p2,head;
	int n=0;
	head=NULL;
	p1=p2=(log_node)malloc(LEN);
	scanf("%c",&p1->data);
	while(p1->data!='\n')
	{
		n=n+1;
		if(1==n)
		head=p1;
		else
		p2->next=p1;
		p2=p1;
		p1=(log_node)malloc(LEN);
		scanf("%c",&p1->data);			//第一次没打&符号，导致不可查出的错误 。下次仔细！！！ 
	}
	p2->next=NULL;
	return head;
}
int length(log_node list)
{
	log_node p;
	p=list;
	int n=0;
	while(p)
	{
		n=n+1;
		p=p->next;
	}
	return n;
}
int main()
{
	log_node list;
	int n;
	printf("请输入链表:");
	list=creat();
	n=length(list);
	printf("此链表的长度为：%d",n);
	getchar();
	return 0; 
}
