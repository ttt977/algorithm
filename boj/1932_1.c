#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

int samgak[501][501];
int maxv[501][501];
int N=0;

int solve(int i, int j)
{
	if(maxv[i][j] != -1)
	 return maxv[i][j];
	 
	if( i<0 || j<0 )
	 return 0;
	 
	if(i+1<j)
	 return 0;
	 
	if(i==0 && j==0)
	{
		return maxv[i][j]=samgak[i][j];
	}
	else if(i==0 && j==1)
	{
		return maxv[i][j]=0;
	}	
	else if(i==1 && j==0)
	{
		return maxv[i][j]=samgak[i][j] + samgak[0][0];
	}	
	else
	{							
	 maxv[i][j]=samgak[i][j] + MAX(solve(i-1,j),solve(i-1,j-1));			
	}	
	return maxv[i][j];
}

int main()
{
	int i=0,j=0;
	int max=0,tmp=0;
	memset(samgak,0,sizeof(samgak));
	memset(maxv,-1,sizeof(maxv));
	
	scanf("%d",&N);
	
	for(i=0;i<N;i++)
	{
		j=0;
		do
		{
			scanf("%d",&(samgak[i][j++]));
		}
		while (getc(stdin) == ' ');
	}
	
	solve(N-1,N-1);
	
/*			
	printf("\n");
	printf("\n");

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",samgak[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	printf("\n");
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d ",maxv[i][j]);
		}
		printf("\n");
	}
*/
	for(j=0;j<N;j++)
	{
		tmp = maxv[N-1][j];
		if(tmp > max)
		 max = tmp;
	}	
	
	printf("%d\n",max);
}

