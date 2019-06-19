#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>

using namespace std;
typedef pair<int,pair<int,int> > pii; //q에 들어가 데이터 i,j 좌표 및 현재 레벨(거리) 

int H;
int W;

char map[510][510];
char visited[510][510];

void input_data(){
	int i;
	cin >> H >> W;
	for(i=0 ; i<H ; i++){
		cin >> map[i];	
	}	
}

int bfs(int i, int j) //i,j 위치부터 bfs 
{
	int arri[4] = {0,1,0,-1}; //좌/상/우/하 순서로 탐색 
	int arrj[4] = {-1,0,1,0};
	int level = 0;

	queue<pii> q;
	q.push(make_pair(i,make_pair(j,level))); //시작 위치 q에 push 
	visited[0][0] = 1;

	while(!q.empty()) //q가 빌 때까지 
	{
	  //q에서 값 가져오기 
	 int cur_i = q.front().first;
	 int cur_j = q.front().second.first;
	 int cur_lvl = q.front().second.second;
	 
	 //값 삭제 
	 q.pop();

	 for(int k=0;k<4;k++) //좌/상/우/하 탐색 
	 {		
		int n_i = cur_i + arri[k]; //탐색 위치 설정 
		int n_j = cur_j + arrj[k];
		if(n_i < 0 || n_j < 0 || n_i > H-1 || n_j > W-1) //범위 벗어나는가 
		 continue;

		if(visited[n_i][n_j] == 0 && map[n_i][n_j] != 'X') //방문하지 않은 곳이고 공원이 아니면 
		 {
			visited[n_i][n_j] = 1; //방문처리 
			if(n_i == H-1 && n_j == W-1) //도착위치에 있냐? 
 	  		 return cur_lvl+1;
			q.push(make_pair(n_i,make_pair(n_j,cur_lvl+1))); //방문할 후보로 q에 push 
		 }
	 }
	}
    return -1;
}

int main(){
	int ans = 0;
	input_data();
	memset(visited,0,sizeof(visited));
	ans = bfs(0,0);
	cout << ans << endl;
	return 0;
}
