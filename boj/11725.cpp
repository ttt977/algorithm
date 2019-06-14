#include <iostream>
#include <queue>

using namespace std;
typedef pair<int,int> pii;

int N;
vector<int> v[100001];
queue<pii> q;
int parents[100001];

int main(void)
{
	int tmpa,tmpb;
	cin >> N;
	for(int i=1;i<=N-1;i++)
	{
		cin >> tmpa >> tmpb;
		v[tmpa].push_back(tmpb);		
		v[tmpb].push_back(tmpa);
	}

	parents[0] = -1;
	parents[1] = -1;

	for(int i=0;i<v[1].size();i++)
	{
		int paren = 1;
		int child = v[1][i];
		q.push(make_pair(paren,child));
	}
	while(!q.empty())
	{
		int cur_p = q.front().first;
		int cur_c = q.front().second;

		q.pop();
		parents[cur_c] = cur_p;

		for(int k=0;k<v[cur_c].size();k++)
		{
			int paren = cur_c;
			int child = v[cur_c][k];
			if(parents[child] == 0)
			 q.push(make_pair(paren,child));
		}		
	}

	for(int i=2;i<100001;i++)
	{
		if(parents[i] == 0)
		 break;
		else
		 printf("%d\n",parents[i]);
	}

	return 0;
}
