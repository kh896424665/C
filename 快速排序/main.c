#include <stdio.h>
#include <stdlib.h>
#define max 8 
typedef struct node
{
	int key;
}node;
int hoare(struct node r[max],int f,int h)
{
	int i,j;
	i=f;
	j=h;
 	node pivot;
	pivot=r[i];//
	do 
	{
		while((i<j)&&(r[j].key>=pivot.key))   j++;
		if(i<j)
		{
		r[i].key=r[j].key;
		i++;
		}
		while((i<j)&&(r[i].key<=pivot.key))	  i++;
		if(i<j)
		{
		r[j].key=r[i].key;
		j--;		
		}	
	}while(i<j);
	r[i]=pivot;
	return i;
}
void quicksort(struct node r[],int f,int h)
{
	int i;
	if(f<h)
	{
		i=hoare(r,f,h);
		quicksort(r,f,i-1);
		quicksort(r,i+1,h);
	}
}
int main()
{
	node r[max];
	int i,f,h;
	printf("ÊäÈë%d¸öÊý×Ö£º",max);
	for(i=0;i<max;i++)
	{
		scanf("%d",&r[i].key);
	}
	f=0;
	h=max-1;
	quicksort(r,f,h);
	for(i=0;i<max;i++)
	{
		printf("&d ",r[i].key);
	}
	
}
