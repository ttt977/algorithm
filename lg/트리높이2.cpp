#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int V,E;
int ans1 = 0;//가장 긴 값 
int ans2 = 987654321;//가장 짧은 값 

vector<int> v[1010];
int visited[1010]; //방문여부 및 현재 레벨 확인 용(0이면 방문안한곳) 

void bfs() //노드 0에서 모든 노드 너비우선탐색 
{
	queue<int> q;
	q.push(0); //노드를 넣고 
	visited[0] = 0; 
	while(!q.empty())
	{
		int cur_v = q.front(); //q 제일 앞위치 노드 가져오고 
		q.pop(); //q에서 꺼내기 
		for(int i=0;i<v[cur_v].size();i++) // 가져온 노드와 연결된 노드 가져오기 위함 
		{
			int now_v = v[cur_v][i];
			if(visited[now_v] == 0) //방문하지 않은 곳이면 
			{
			 visited[now_v] = visited[cur_v]+1; //부모 노드의 레벨 값 +1 
			 q.push(now_v);//여기서 부터 연결된 노드 확인하기 위해 q에 넣기 
			}
		}		
	}
	for(int i=1;i<V;i++) //최대 레벨 값 확인 
	{	 
	 if(visited[i] > ans1)
	  ans1 = visited[i];	 
	}	
}

int main(void)
{
	int start=0,end=0;
	
	cin >> V >> E;
	for(int i=0;i<E;i++)
	{
	 cin >> start >> end;
	 v[start].push_back(end); //start 노드에서 end 노드 연결을 벡터활용표현 
	}
	bfs();
	for(int i=0;i<V;i++) //연결된 노드가 없는 것(leaf 노드) 중 최소 값 확인 
	{
		if(v[i].size() != 0)
		 continue;
		if(visited[i] < ans2)
		 ans2 = visited[i];		
	}
	cout << ans1 - ans2 << endl;
	return 0;
}
