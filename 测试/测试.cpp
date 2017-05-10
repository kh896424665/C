#include<stdio.h>
int main()
{
    long long int a,b,c,z;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3)
    {
    	z=b*b-4*a*c;
    	if(z>0)
    	printf("2");
    	if(z<0)
    	printf("0");
    	else
    	printf("1");
    }
    
}
