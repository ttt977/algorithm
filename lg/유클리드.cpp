#include <stdio.h>

unsigned int gcd(int a, int b)
{
	unsigned int tmp=0;

	if(a%b == 0)
	{
	 return b;
	}
	 
	tmp = a%b;
	
	return gcd(b,tmp);
}

int main()
{
	unsigned int a=0,b=0;
	scanf("%d %d",&a,&b);
	
	printf("%d\n",gcd(a,b));	
}



