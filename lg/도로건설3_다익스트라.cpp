//다익스트라 알고리즘 활용 최단비용계산 

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int,pair<int,int> > pii; //현재까지 거리,x,y 위치 저장 

int N;//지도 크기
char map[110][110];//지도 정보
int visited[110][110];//방문여부체크 

void Input_Data(){
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> map[i];
	}
}

int bfs(int y, int x) //y,x 위치에서 N-1,N-1 위치까지의 최단 경로를 반환
{
	int arri[4] = {0,-1,0,1}; //좌/상/우/하 방문 
	int arrj[4] = {-1,0,1,0};
	
	priority_queue<pii> q; //현재 위치에서 상/하/좌/우중 비용이 적은 것을 우선으로 탐색하기 위함 
	q.push(make_pair(0,make_pair(y,x))); //초기 거리,위치 q에 push 
	visited[y][x] = 1;
	
	while(!q.empty())
	{
		int cur_d = q.top().first;
		int cur_i = q.top().second.first;
		int cur_j = q.top().second.second;
		cur_d *= -1; //들어갈 때 (-) 했으므로 뺄때도 (-) 필요 
		if(cur_i == N-1 && cur_j == N-1)
				return cur_d;
		q.pop();
		for(int k=0;k<4;k++)
		{
			int ni = cur_i + arri[k];
			int nj = cur_j + arrj[k];			
			int nd = 0;
			if(ni < 0 || nj < 0 || ni > N-1 || nj > N-1) //범위초과냐? 
				continue;			
			if(visited[ni][nj] != 0) //기존방문했냐? 
				continue;
			visited[ni][nj] = 1; //방문체크
			nd = cur_d + (map[ni][nj] - '0'); //이전에방문했던 노드까지 거리 + 내 위치의 값 더하기 
			nd *= -1;  //작은 값 기준으로 우선순위큐에서 뽑아내기 위함 
			q.push(make_pair(nd,make_pair(ni,nj)));						
		}
	}	
}

int main(){
	int ans = -1;
	Input_Data();
  	ans = bfs(0,0);
	cout << ans << endl;
	return 0;
}

