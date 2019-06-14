#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef pair<int,int> pii;


int N,M,V;
vector<int> con[1001];
int visited[1001];

int dfs(int s)
{
  printf("%d ",s);
  visited[s] = 1;
  priority_queue<int> pq;
  for(int i=0;i<con[s].size();i++)
  {	
	int next_node = con[s][i];
	next_node *= -1;
	pq.push(next_node);	
  }
  while(pq.empty() == 0)
  {
	int nn = pq.top();
	nn *= -1;
	if(visited[nn] == -1)
	 dfs(nn);
	pq.pop();
  }
}

int bfs(int s)
{
  queue<int> q;  
  q.push(s);
  while(q.empty() == 0)
  {
	priority_queue<int> pq;
	int qt = q.front();
	q.pop();	
	if(visited[qt] == -1)
	{
	 printf("%d ",qt);
	 visited[qt] = 1;
	}
	for(int i=0;i<con[qt].size();i++)
	{	
	 int next_node = con[qt][i];
	 if(visited[next_node] == -1)
	 {
	  next_node *= -1;
	  pq.push(next_node);		 
	 }
	}
	while(!pq.empty())
	{
	 int ct = pq.top();
	 pq.pop();
	 ct*=-1;
	 q.push(ct);
	}
  }
}

int main(void)
{
	cin >> N >> M >> V;
	for(int i=0;i<M;i++)
	{
		int start=0,end=0;
		scanf("%d %d",&start,&end);
		con[start].push_back(end);
		con[end].push_back(start);
	}
	memset(visited,-1,sizeof(visited));
	dfs(V);
	memset(visited,-1,sizeof(visited));
	cout << endl;
	bfs(V);

	return 0;
}

