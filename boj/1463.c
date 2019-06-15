#include <stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))

unsigned int dp[1000001]={0};

unsigned int makeone(int n)
{
	if(dp[n] != -1)
	 return dp[n];

	if(n%3 == 0 && n%2 == 0)
		return dp[n] = MIN(makeone(n/3),makeone(n/2))+1;
	else if(n%3 == 0)
		return dp[n] = MIN(makeone(n/3),makeone(n-1))+1;
	else if(n%2 == 0)
		return dp[n] = MIN(makeone(n/2),makeone(n-1))+1;
	else 
		return dp[n] = makeone(n-1) + 1;
}

int main()
{
	int n=0,i=0;
	
	scanf("%d",&n);
	
	for(i=0;i<=n;i++)
	 dp[i]=-1;

	dp[0] = 0;
	dp[1] = 0;	 
	dp[2] = 1;
	dp[3] = 1;
	makeone(n);
	
	printf("%d\n",dp[n]);
	return 0;
}
