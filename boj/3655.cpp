#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int adj[501][501];
int degree[501];

int tc,n,m;
int t[501];
queue<int> q;
queue<int> rq;

void q_clean(queue<int> &a)
{
	while(!a.empty())
	{
		a.pop();
	}
}

int main(void)
{
	int tmp,tmp1;
	cin >> tc;


for(int test=0;test<tc;test++)
{
	
	memset(adj,0,sizeof(adj));
	memset(degree,0,sizeof(degree));
	memset(t,0,sizeof(t));
	q_clean(q);
	q_clean(rq);	

	cin >> n;

	for(int i=0;i<n;i++)
	{
		scanf("%d",t+i);		
	}

	for(int i=0;i<n;i++)
	{
	 for(int j=i+1;j<n;j++)
	 {
		adj[t[i]][t[j]] = 1;
		degree[t[j]]++;
	 }
	}

	cin >> m;

	for(int k=0;k<m;k++)
	{
		scanf("%d %d",&tmp,&tmp1);
		if(adj[tmp][tmp1] == 1)
		{
		 adj[tmp][tmp1] = 0;
		 degree[tmp1]--;
		 adj[tmp1][tmp] = 1;
		 degree[tmp]++;
		}
		else
		{
		  adj[tmp][tmp1] = 1;
		  degree[tmp1]++;
		  adj[tmp1][tmp] = 0;
		  degree[tmp]--;
		}		
	}

	for(int i=1;i<=n;i++)
	{
		if(degree[i] == 0)
		 q.push(i);		 
	}	

	while(!q.empty())
	{
		if(q.size() > 1)
		{	
		 break;
		}
		int cur = q.front();
		q.pop();		
		rq.push(cur);
		for(int x=1;x<=n;x++)
		{
			if(adj[cur][x] == 1)
			{			 
			 degree[x]--;
			 if(degree[x] == 0)
			 {
	 		   q.push(x);
			 }	
			}
		}
	}

	if(rq.size() != n)
	 printf("IMPOSSIBLE\n");
	else if(q.size() > 1)
	 printf("?\n");
	else
	{
		while(!rq.empty())
		{
			printf("%d ",rq.front());
			rq.pop();
		}
		printf("\n");
	}

}
	return 0;
}
