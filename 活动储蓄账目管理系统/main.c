#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define DATA_FILE data.dat	//�궨���ļ�����
typedef struct log
{
	char DateTime[25];
	char W_D;
	float Amount;
} log;	//�����ȡ��¼���ݽṹ
typedef struct nod_log
{
	log data;
	struct nod_log *next;
} nod_log,*p_nod_log;	//�����ȡ��¼����ڵ����ͣ�����log���͵��������ָ����һ�ڵ��ָ����
typedef struct account
{
	char ID[10];
	char Name[10];
	float Balance;
} account;//�����˻���������
typedef struct node_account
{
	account data;
	struct node_account *nlog;
	struct node_account *next; 
} node_account,*p_node_account;	//����ڵ����ͣ������˻���Ϣ���ݺ�ָ����һ�ڵ��ָ�����ָ��洢��¼��ָ��
p_node_account headAccount;	//�����˻���Ϣ�����ͷָ��Ϊȫ�ֱ���

//��������
void PrintAccountTitle;
void PrintAccount(account);
void PrintLogTitle();
void PrintLog(log);
void Read;
void Write();
void List(int);
void Creat();
void Distroy();
void Deposit();
void Withdraw();
void FreeLogs(p_node_log);
p_node_account FindAAccount(char*);	//
//ϵͳ������
void main()
{
	char choice='0';
	headAccount=NULL;
	do
	{
		system("cls");
		printF("----------------�˵�--------------\n");	//��ʾ���˵�
		printf("----------------------------------\n\n");
		printf("1. �����ļ���\n");
		printf("2. ����������\n");
		printf("3. ����������\n");
		printf("4. ������\n");
		printf("5. ����ȡ�\n"); 
		printf("6. ��ʾȫ���˻���\n"); 
		printf("7. �����˻���\n"); 
		printf("8. ���ҽ��׼�¼��\n"); 
		printf("9. д���ļ���\n"); 
		printf("0. �˳�ϵͳ��\n"); 
		printf("----------------------------------\n\n");
		printf("Please make a choice:");
		scanf("%c",&choice);
		switch(choice)
		{
			case '1':	//��ȡ�ļ� 
				Read;	break;
			case '2':	//�����˻����� 
				Creat();	break;
			case '3':	// ɾ���˻� 
				Distroy();	break;
			case '4':	//���� 
				Deposit();	break;
			case '5':	//ȡ��� 
				Withdraw();	break;
			case '6':	//��ʾȫ���˻���Ϣ 
				List(0);	break;
			case '7':	//�����˻� 
				List(1);	break;
			case '8':	//���ҽ��׼�¼ 
				List(2);	break;
			case '9':	//д���ļ� 
				Write(); break;
			case '0':	//�˳�ϵͳ 
				break;
			default:	//����Ƿ� 
			printf("�Ƿ�ѡ��");
		} 
	}while(choice!='0');
}
void PrintAccountTitle()	//��������ʽ 
{
	printf("------------------------------------------\n");
	printf("	ID		|	Name	|	Balance		");
}
void PrintAccount(account p)	//����˺��������� 
{
	printf("	%10s	|	%10s	|	%f\n",p.ID,p.Name,p.Balance);
} 
void PrintLogTitle()		//��������ʽ 
{
	printf("-----------------------------------------\n");
	printf("	DataTime	|	W or D	|	Amount	\n"); 
}
void PrintLog(log p)		//��ӡ�洢���ڣ���ȡ��־����� 
{
	printf("  %24s  |  %c   |  %f\n",p.DateTime,p.W_D,p.Amount);
}
 
