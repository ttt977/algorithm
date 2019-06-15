#include <stdio.h>

int main(void)
{
	int N=0,i=0,sum=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		sum+=i;
	}	
	printf("%d\n",sum);
}
