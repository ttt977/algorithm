#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int result[41] = {0};

int fibo(int n)
{
	int rst = 0;
	
	if(result[n] != 0 && n != 0)
	return result[n];
	
	if(n == 0){
		result[n] = 0;
		return 0;
	}
	else if(n == 1){
		result[n] = 1;
		return 1;
	}	 
	else
	{
		rst = fibo(n-1) + fibo(n-2);
		result[n] = rst;
		return rst;
	}
}

int main()
{
	int tcnt = 0;
	int i=0,fresult=0;
	int *tc = NULL;
	
	scanf("%d",&tcnt);
	tc = (int *)malloc(sizeof(int)*tcnt);
	memset(result,0,sizeof(result));
	
	for(i=0;i<tcnt;i++)
	{
		scanf("%d",tc + i);
		fibo(tc[i]);
		if(tc[i] == 0)
		 printf("1 0\n");
		else
		 printf("%d %d\n",result[tc[i]-1],result[tc[i]]);
	}	
}

