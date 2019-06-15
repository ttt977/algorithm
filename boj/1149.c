#include <stdio.h>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MIN3(a,b,c) (MIN(a,b)<(c)?MIN(a,b):c)

int min_n[1001][3]={0};
int r[1001]={0};
int g[1001]={0};
int b[1001]={0};

void solve(int n)
{
	int tmp=0;
	
	if(n !=0 && min_n[n][0] != 0)
	{
		return;
	}
	
	if(n==0)
	{
	 min_n[0][0]=0;
	 min_n[0][1]=0;
	 min_n[0][2]=0;
	}
	else if(n==1)
	{
	 min_n[1][0] = r[1];
	 min_n[1][1] = g[1];
	 min_n[1][2] = b[1];
	}
	else
	 {
	 	solve(n-1);
	 	
	 	min_n[n][0] = (r[n] + MIN((min_n[n-1][1]),(min_n[n-1][2])));
	 	min_n[n][1] = (g[n] + MIN((min_n[n-1][0]),(min_n[n-1][2])));
	 	min_n[n][2] = (b[n] + MIN((min_n[n-1][0]),(min_n[n-1][1])));
	 }
}

int main()
{
	int N=0,i=0;
	scanf("%d",&N);
	
	r[0]=0;
	g[0]=0;
	b[0]=0;
	
	for(i=1;i<=N;i++)
	{
		scanf("%d %d %d",r+i,g+i,b+i);
	}
	
	for(i=0;i<=N;i++)
	{
		min_n[i][0]=0;
		min_n[i][1]=0;
		min_n[i][2]=0;		
	}
	
	solve(N);
	#if 0
	for(i=0;i<=N;i++)
	{
		printf("%d: %d %d %d\n",i,min_n[i][0],min_n[i][1],min_n[i][2]);
	}
	#endif
	
	printf("%d\n",MIN3(min_n[N][0],min_n[N][1],min_n[N][2]));
	return 0;
}

