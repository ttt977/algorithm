#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main()
{
	int i = 0, j = 0, N = 0, tmp = 0;
	int orderarr[10001] = {0};
	
	scanf("%d",&N);
		
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d",&tmp);
		(orderarr[tmp])+=1;
	}
		
	for(i = 1 ; i < 10001 ; i++)
	{
		if(orderarr[i] != 0)
		{
	     while(orderarr[i] > 0)
	     {
		  printf("%d\n",i);
		  (orderarr[i])-=1;
	 	 }
		}
	}
}

