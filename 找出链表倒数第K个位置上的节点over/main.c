#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct arr)
struct arr            //������� 
{
	char data;
	struct arr *next;
};
int n;
struct arr *creat(void)		//���������� 
{
	struct arr *head,*p1,*p2;
	n=0;
	p1=p2=(struct arr*)malloc(LEN);
	scanf("%c",&p1->data);
	head=NULL;
	while(p1->data!='\n')				//������س�ʱѭ������ 
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
int locate(struct arr *list,int k)		//��λ���� 
{
	struct arr *p1,*p2;
	int i;
	p1=list;
	p2=list;
	for(i=1;i<=k;i++)
	{
		if(p1->next==NULL) 
		return 0;					//����С��K������0 
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
	printf("�������������ݣ��ַ�����:") ; 
	list=creat();
	printf("Ҫ�ҵ����ڼ����ڵ㣺");
	scanf("%d",&k); 
	printf("������K�������:");
	y=locate(list,k);
	if(0==y)	printf("������С��k��"); 
	getchar();
	return 0;
	 
}
