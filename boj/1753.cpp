#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321
typedef pair<int,int> pii;

int V,E,k;
long d[20001];


vector<int> con[20001],conv[20001];

int main(void)
{
	int u=0,v=0,w=0;
	cin >> V >> E;	
	cin >> k;
	
	for(int i=1;i<=V;i++)
	{
		con[i].clear();
		conv[i].clear();
	}
	
	for(int i=1;i<=E;i++)
	{
		//cin >> u >> v >> w;
		scanf("%d %d %d",&u,&v,&w);
		con[u].push_back(v);
		conv[u].push_back(w);
	}
	
//	cout << con[1][1] << " " << conv[1][1] << endl;
	
	for(int i=1;i<=V;i++)
	 d[i] = INF;
	 
	d[k] = 0;
	
	priority_queue<pii > pq;
	
	pq.push(make_pair(0,k));
	
	while(!pq.empty())
	{
		int q = pq.top().second, dist = -pq.top().first;
		pq.pop();
		
		if(d[q] < dist ) continue;
		
		for(int i=con[q].size()-1;i>=0;i--)
		{
			//cout << q << " " <<  i  << " " <<  con[q][i] << " " << conv[q][i] << endl;
			int t = con[q][i], v= conv[q][i];
			if(d[t] > d[q]+v)
			{
				d[t] = d[q]+v;
				pq.push(make_pair(-d[t],t));
			}
		}
	}
	

	
	for(int i=1;i<=V;i++)
	{
		if(d[i] == INF)
			printf("INF\n");
		else
			printf("%d\n",d[i]);
	}
	
}

