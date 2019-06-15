#include <stdio.h>
#include <memory.h>

int cache[50]={0,};

int solve(int n)
{
	if(cache[n] != -1)
	 return cache[n];
	 
	if(n == 0)
	 return cache[n] = 0;
	else if(n == 1)
	 return cache[n] = 1;
	else
	 return cache[n] = solve(n-2) + solve(n-1);
}

int main(void)
{
	int n = 0, i = 0;
	memset(cache,-1,sizeof(cache));
	scanf("%d",&n);
	printf("%d\n",solve(n));
}
