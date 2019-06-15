#include <stdio.h>

unsigned long long solve[1000001][2];

unsigned long long tile(int n)
{
	int i=0,j=0;
	
	solve[0][0] = 1ul;
	solve[1][0] = 2ul;	
	solve[2][0] = 7ul;		
	
	for(j=3;j<=n;j++)	
	{
		solve[j][1]=((solve[j-1][1] + solve[j-3][0]*2)%1000000007ul);		 
		solve[j][0]=((solve[j-1][0]*2 + solve[j-2][0]*3 + solve[j][1])%1000000007ul);
	}						 
}

int main()
{
	int N=0,i=0;
		 
	scanf("%d",&N);
	tile(N);
	
	printf("%llu\n",solve[N][0]);
}
