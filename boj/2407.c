#include <stdio.h>

unsigned long long memoryu[101][101]={0};
unsigned long long memoryd[101][101]={0};

int main()
{
	int n=0,m=0,i=0,j=0;
	
	scanf("%d %d",&n,&m);
	for(i=0;i<101;i++)
	{
		for(j=0;j<101;j++)
		{
		 memoryu[i][j]=0;
		 memoryd[i][j]=0;
		}
	}
	
	memoryd[0][0]=1;
	memoryd[0][1]=1;
	memoryd[1][0]=1;
		
	for(i=1;i<101;i++)
	{
		for(j=0;j<=i;j++)
		{
		 if(i==j || j==0)
		  memoryd[i][j] = 1;
		 else
		  {
			memoryd[i][j] = memoryd[i-1][j-1] + memoryd[i-1][j];
			memoryu[i][j] = memoryu[i-1][j-1] + memoryu[i-1][j];
			  
			if(memoryd[i][j] >= 100000000000000000)
			{
				memoryu[i][j]++;				
				memoryd[i][j] -= 100000000000000000;
			}		  	
		  }
		}
	}
	
	
	if(memoryu[n][m] != 0)
	 printf("%llu%llu\n",memoryu[n][m],memoryd[n][m]);
	else
	 printf("%llu\n",memoryd[n][m]);
	
	return 0;
}
