#include <stdio.h>
#include<math.h>
int main()
{
	float a,x;
	scanf("%f",&a);
	x=a;
	while(fabs(x*x-a)>=0.00001)
	{
		x=(x+a/x)/2;
	}
	printf("%.3f",x);
} 
