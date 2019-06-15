#include <stdio.h>
#include <memory.h>

int D[1001]={0,};
int rule[100001][2]={0,};
int N=0,K=0,w=0;
int wtime[1001]={0,};

int initarray()
{
	memset(D,-1,sizeof(D));
	memset(wtime,-1,sizeof(wtime));
	memset(rule,0,sizeof(rule));
}

int maxpindex(int n)
{
	int i=0,j=0,a=0,tmp=0,max=0;
	int candp = -1;
	
//	printf("maxpindex(%d)\n",n);
	
	for(i=0;i<K;i++)
	{
		if(rule[i][1] == n)
		{
		//	printf("same with n %d\n",i);
			tmp=D[rule[i][0]-1];
			if(tmp > max)
			{
			 max = tmp;
			 candp=i;
			}
		}
	}
	if(candp == -1)
	 return 99999;
	else
	{
//	printf("candp : %d, number : %d\n",candp,rule[candp][0]);
	return rule[candp][0];
	}	
}

int solve(int w)
{
//	printf("solve(%d) in\n",w);
	
	if(w == 99999)
	{
		return 0;
	}
	
	if(wtime[w] != -1)
	 return wtime[w];	 	 
	
	return wtime[w] = D[w-1] + solve(maxpindex(w));	
}

int main()
{
	int tc=0,a=0,b=0;
	scanf("%d",&tc);
	for(a=0;a<tc;a++)
	{
		initarray();
		scanf("%d %d",&N,&K);
		for(b=0;b<N;b++)
		{
			scanf("%d",&(D[b]));
		}
		for(b=0;b<K;b++)
		{
			scanf("%d %d",&(rule[b][0]),&(rule[b][1]));
		}
		scanf("%d",&w);
		solve(w);
		printf("%d\n",wtime[w]);
		#if 0
		for(b=0;b<=w;b++)
		{
		printf("wtime[%d] = %d\n",b,wtime[b]);		
		}	
		#endif	
	}
}
