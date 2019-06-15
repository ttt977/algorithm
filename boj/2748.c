#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

unsigned long long dp[100000000] = {0};

unsigned long long fibo(int n)
{
	if(dp[n] != 0)
	 return dp[n];
	 
	else if(n == 0){
		dp[n] = 0;
		return 0;
	}
	else if(n == 1) {
		dp[n] = 1;
		return 1;		
	}
	else
	{
		dp[n] = fibo(n-1) + fibo(n-2);
		return dp[n];
	}
}

int main()
{
	int n = 0;
	scanf("%d",&n);
	fibo(n);
	printf("%llu",dp[n]);
}
