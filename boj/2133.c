#include <stdio.h>

int solve[31];

int tile(int n)
{
	int i=0;
	
	if(solve[n] != -1)
	 return solve[n];
	 
	if(n%2 == 1)
	 return solve[n] = 0;
	else if(n==0)
	 return solve[n] = 1;
	else if(n==2)
	 return solve[n] = 3;
	else
	{
		solve[n]=tile(n-2)*3;
		for(i=4;i<=n;i+=2)
		 solve[n]+=tile(n-i)*2;		 
		return solve[n];
	}	 
}

int main()
{
	int N=0,i=0;
	
	for(i=0;i<31;i++)
	 solve[i] = -1;
	 
	scanf("%d",&N);
	tile(N);
	
	printf("%d\n",solve[N]);
}
