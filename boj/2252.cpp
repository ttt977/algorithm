#include <iostream>
#include <queue>

using namespace std;
int N,M;

vector<int> v[32001];
queue<int> q;
int degree[32001];

int main(void)
{
	int a=0,b=0;
	cin >> N >> M;

	for(int i=0;i<M;i++)
	{
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		degree[b]++;
	}

	for(int i=1;i<=N;i++)
	{
		if(degree[i] == 0)
		 q.push(i);
	}

	while(!q.empty())
	{
		int cur = q.front();
		cout << cur <<" ";
		q.pop();
		for(int i=0;i<v[cur].size();i++)
		{
			int tmp = v[cur][i];
			degree[tmp]--;
			if(degree[tmp] == 0)
			 q.push(tmp);
		}	
	}

	return 0;
}
