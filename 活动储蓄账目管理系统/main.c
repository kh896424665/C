#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define DATA_FILE data.dat	//宏定义文件名称
typedef struct log
{
	char DateTime[25];
	char W_D;
	float Amount;
} log;	//定义存取记录数据结构
typedef struct nod_log
{
	log data;
	struct nod_log *next;
} nod_log,*p_nod_log;	//定义存取记录链表节点类型，包括log类型的数据域和指向下一节点的指针域
typedef struct account
{
	char ID[10];
	char Name[10];
	float Balance;
} account;//定义账户数据类型
typedef struct node_account
{
	account data;
	struct node_account *nlog;
	struct node_account *next; 
} node_account,*p_node_account;	//定义节点类型，包括账户信息数据和指向下一节点的指针域和指向存储记录的指针
p_node_account headAccount;	//定义账户信息链表的头指针为全局变量

//声明函数
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
//系统主函数
void main()
{
	char choice='0';
	headAccount=NULL;
	do
	{
		system("cls");
		printF("----------------菜单--------------\n");	//显示主菜单
		printf("----------------------------------\n\n");
		printf("1. 读入文件；\n");
		printf("2. 储户开户；\n");
		printf("3. 储户销户；\n");
		printf("4. 储户存款；\n");
		printf("5. 储户取款；\n"); 
		printf("6. 显示全部账户；\n"); 
		printf("7. 查找账户余额；\n"); 
		printf("8. 查找交易记录；\n"); 
		printf("9. 写入文件；\n"); 
		printf("0. 退出系统；\n"); 
		printf("----------------------------------\n\n");
		printf("Please make a choice:");
		scanf("%c",&choice);
		switch(choice)
		{
			case '1':	//读取文件 
				Read;	break;
			case '2':	//创建账户链表 
				Creat();	break;
			case '3':	// 删除账户 
				Distroy();	break;
			case '4':	//存款功能 
				Deposit();	break;
			case '5':	//取款功能 
				Withdraw();	break;
			case '6':	//显示全部账户信息 
				List(0);	break;
			case '7':	//查找账户 
				List(1);	break;
			case '8':	//查找交易记录 
				List(2);	break;
			case '9':	//写入文件 
				Write(); break;
			case '0':	//退出系统 
				break;
			default:	//输入非法 
			printf("非法选择！");
		} 
	}while(choice!='0');
}
void PrintAccountTitle()	//输出界面格式 
{
	printf("------------------------------------------\n");
	printf("	ID		|	Name	|	Balance		");
}
void PrintAccount(account p)	//输出账号姓名余额函数 
{
	printf("	%10s	|	%10s	|	%f\n",p.ID,p.Name,p.Balance);
} 
void PrintLogTitle()		//输出界面格式 
{
	printf("-----------------------------------------\n");
	printf("	DataTime	|	W or D	|	Amount	\n"); 
}
void PrintLog(log p)		//打印存储日期，存取标志，金额 
{
	printf("  %24s  |  %c   |  %f\n",p.DateTime,p.W_D,p.Amount);
}
 
