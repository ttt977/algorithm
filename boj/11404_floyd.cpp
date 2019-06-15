//모든 쌍에 대한 최소 비용 계산 

#include <iostream>

using namespace std;
#define INF 987654321

int n,m;
int adj[110][110];

int main(void)
{
	int from,to,exp;
	int k;

	//일단 모든 경로의 비용을 INF로 표시
	for(int i=0;i<110;i++)
	{
	 for(int j=0;j<110;j++)
	 {
	  if(i==j) // 자기자신으로 가는 비용은 0 
	   adj[i][j] = 0;
	  else
	   adj[i][j] = INF;
	 }
	}

	cin >> n;
	cin >> m;
	for(int i=0;i<m;i++)
	{
	  //구간/비용 입력 
	 scanf("%d %d %d",&from,&to,&exp);
	 if(adj[from][to] > exp) //기존에 들어있는 값이 새로 입력되는 비용보다 클때만 업데이트 
	  adj[from][to] = exp;
	}

	for(int k=1;k<=n;k++) //각 거쳐가는 도시(정점) 
	{
	 for(int i=1;i<=n;i++)
	 {
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			 continue;
			int new_d = adj[i][k] + adj[k][j]; //거쳐가는 경우의 거리 
			if(adj[i][j] > new_d ) //거쳐가는 경로가 비용이 더 작을경우 교체 
			 adj[i][j] = new_d;
		}
	 }
	}

	for(int i=1;i<=n;i++)
	 {
		for(int j=1;j<=n;j++)
		{			
			if(adj[i][j] == INF )
			 printf("0 ");
			else
			 printf("%d ",adj[i][j]);
		}
		printf("\n");
	 }
		
	return 0;
} 
