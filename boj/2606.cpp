//dfs
//컴퓨터 번호가 1부터 시작됨을 주의
//1번에 의해서 감염된 수를 구하는 것임을 주의 

#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

int N,M;

vector<int> com[101];
int visited[101];

void dfs(int no)
{
	if(com[no].size() == 0)
	 return;

	visited[no] = 1; //방문처리 

	for(int i=0;i<com[no].size();i++) //방문한 노드에 연결된 노드들 방문 
	{
		int cur_com = com[no][i];
		if(visited[cur_com] == -1) //방문하지 않은 곳이라면 
		{
			dfs(cur_com); //다시 방문 
		}		
	}
}

int main(void)
{
	int start,end;
	int ans = 0;

	memset(visited,-1,sizeof(visited));

	cin >> N ;
	cin >> M;

	for(int i=0;i<M;i++)
	{
		cin >> start >> end;
		com[start].push_back(end);
		com[end].push_back(start);//양방향이므로 반대쪽에서 가는 경로도 추가 필요 
	}

	dfs(1); //1번 노드에서 탐색 시작 
	
	for(int i=1;i<=N;i++)
	{
		if(visited[i] == 1)
		 ans++;
	}
	cout << ans-1 << endl; //1번 컴퓨터는 제외. 
	return 0;
} 
