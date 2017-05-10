#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(node)
typedef struct node
{
	int data;
	struct node *next;
} node;
int main()
{
	node *head,*p,*q;
	int n,i;
printf("输入人数n：");
scanf("%d",&n);
p=head=(node *)malloc(LEN);
p->data=0;
for(i=1;i<n;i++)
{
	q=(node *)malloc(LEN);
	q->data=i;
	p->next=q;
	p=q;
} 
p->next=head;
q=head;
while(q!=q->next)
{
	p=q->next;
	q=p->next;
	p->next=q->next;
	printf("%d  ",q->data);
	free(q);
	q=p->next;
}
printf("\n最后剩下的人序号为%d",q->data);
getche();
return 0;
}
