#include <stdio.h>

long dp[1001][1001] = {0,};

long bino(int n, int k)
{
	if (dp[n][k] != 0)
	 return dp[n][k];
	
	if (n == k || k == 0)
	{
		dp[n][k] = 1;
		return dp[n][k];	
	}	 
	else
	{
		dp[n][k] = bino(n-1,k-1)%10007 + bino(n-1,k)%10007;
		return dp[n][k];
	}	 
}

int main()
{
	int n=0,k=0;
			
	scanf("%d %d",&n,&k);
	bino(n,k);	
	printf("%d\n",dp[n][k]%10007);
}
