#include <stdio.h>
#include <string.h>

int main(void)
{
	int N=0,i=0,sum=0;
	int num=0;
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		scanf("%1d",&num);
		sum+=num;
	}	
	printf("%d\n",sum);
}
