#include <stdio.h>

int hanoi(int a, int b, int c, int n)
{
	if(n==1)
	 {		    
	 	printf("%d %d\n",a,c);
	 }
	else
	{
		hanoi(a,c,b,n-1);
		printf("%d %d\n",a,c);
		hanoi(b,a,c,n-1);
	}
}

int main()
{
	unsigned long long n=0;
	scanf("%llu",&n);	
	printf("%llu\n",(1<<n)-1);
	hanoi(1,2,3,n);
}
