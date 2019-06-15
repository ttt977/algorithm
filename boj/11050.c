#include <stdio.h>

int dp[11][11] = {0,};

int bino(int n, int k)
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
		dp[n][k] = bino(n-1,k-1) + bino(n-1,k);
		return dp[n][k];
	}	 
}

int main()
{
	int n=0,k=0;
	int i=0,j=0;
		
	scanf("%d %d",&n,&k);
	bino(n,k);	
	printf("%d\n",dp[n][k]);
}
