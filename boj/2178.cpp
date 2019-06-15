//BFS로 미로 상의 최단거리 구하기

#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string>
#include <queue>

using namespace std;

//세로/가로/레벨(최단 거리를 구하기 위함) 
typedef pair<int,pair<int,int> > pii;

int N,M;
int adj[110][110];
int level=0;
queue<pii> q;


 
//아직 방문되지 않은 왼쪽/위/오른쪽/아래 방문 후 queue에 넣기 
void do_visit(int y, int x, int lv)
{
	int arr_i[4] = {0,-1,0,1};
	int arr_j[4] = {-1,0,1,0};

	adj[y][x] = lv;

	for(int k=0;k<4;k++)
	{
		int tmp_i = y+arr_i[k];
		int tmp_j = x+arr_j[k];

		if(tmp_i <1 || tmp_j <1 || tmp_i > N || tmp_j > M)
		 continue;

		if(adj[tmp_i][tmp_j] == 1) //방문가능하면
		{
			adj[tmp_i][tmp_j] = lv+1; //다시 방문하지 않게 레벨값을 넣어둔다 
			q.push(make_pair(tmp_i,make_pair(tmp_j,lv+1))); //여기서부터 다시 탐색을 위해 큐에 넣음 
		}
	}
}

int main(void)
{
	string str;
	cin >> N >> M;
	for(int i=1;i<=N;i++)
	{
		cin >> str;
		for(int j=1;j<=M;j++)
		{
			adj[i][j] = str[j-1]-'0';
		}
	}
#if 0
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
#endif
	//시작 위치 큐에 넣는다.	
	q.push(make_pair(1,make_pair(1,1)));

	while(!q.empty())
	{
		int curi = q.front().first;
		int curj = q.front().second.first;
		int lvl = q.front().second.second;
		q.pop();
		//현 위치부터 각각 방문 
		do_visit(curi,curj,lvl);
	}

#if 0
	for(int i=0;i<=N;i++)
	{
		for(int j=0;j<=M;j++)
		{
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
#endif	
	cout << adj[N][M] << endl;
	return 0;
}
