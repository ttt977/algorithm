#include <stdio.h>
#include <string.h>

int main(void)
{
	int N=0,i=0,j=0;
		
	scanf("%d",&N);
	
	for(i=N;i>=1;i--)
	{
		for(j=i;j<N;j++)
		{
			printf(" ");
		}
		for(j=1;j<=i;j++)
		{
			printf("*");
		}
		printf("\n");	
	}
}
