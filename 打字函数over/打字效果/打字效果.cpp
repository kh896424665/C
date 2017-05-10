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
	slowprint("一个人常常郁闷，通常是由于他没有一个明确的目标。所以说，有目标的人是幸福的，因为他有了方向，不再迷茫！",80);
	getchar();
	return 0;
}