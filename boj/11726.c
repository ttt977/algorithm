#include <stdio.h>

int solve[1001];

int tile(int n)
{
	if(solve[n] != -1)
	 return solve[n];
	 
	if(n<=1)
	 return solve[n] = 1;
	else
	{
		solve[n]=(tile(n-1)+tile(n-2))%10007;
		return solve[n];
	}	 
}

int main()
{
	int N=0,i=0;
	
	for(i=0;i<1001;i++)
	 solve[i] = -1;
	 
	scanf("%d",&N);
	tile(N);
	
	printf("%d\n",solve[N]);
}
