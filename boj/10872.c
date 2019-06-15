#include <stdio.h>

int dp[13]={0};

int fact(int n)
{
	if(dp[n] != 0)
	 return dp[n];
	 
	if (n == 1 || n == 0)
	{
		dp[n] = 1;
		return dp[n];
	}	 
	else
	{
		dp[n] = n*fact(n-1);
		return dp[n];
	}	 
}

int main()
{
	int n=0;
	scanf("%d",&n);
	fact(n);
	printf("%d\n",dp[n]);
}
