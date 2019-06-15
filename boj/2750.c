#include <stdio.h>

int *sort;

int main()
{
	int i = 0, j = 0, N = 0, tmp = 0;
	scanf("%d",&N);
	sort = (int *)malloc(sizeof(int)*N);
	
	
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d",sort+i);
	}
	
	for(i = N-1 ; i > 0 ; i--)
	{
		for(j=i-1;j>=0;j--)
		{
			if(sort[i] < sort[j])
			{
			 tmp = sort[i];
			 sort[i] = sort[j];
			 sort[j] = tmp;		 
			}
		}
	}
	
	for(i = 0 ; i < N ; i++)
	printf("%d\n",sort[i]);	
}

