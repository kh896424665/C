#include<stdio.h>
#include<windows.h>
void slowprint(char* string,int sleeptime)
{
	int i=0;
	for(i=0;string[i]!='\0';i++)
	{
		printf("%c",string[i]);
		Sleep(sleeptime);
	}
}
int main()
{
	slowprint("һ���˳������ƣ�ͨ����������û��һ����ȷ��Ŀ�ꡣ����˵����Ŀ��������Ҹ��ģ���Ϊ�����˷��򣬲�����ã��",80);
	getchar();
	return 0;
}