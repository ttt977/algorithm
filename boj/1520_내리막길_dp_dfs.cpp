//dp/dfs를 활용해서 모든 경로를 구하는 문제
//dfs만 활용시 시간초과 발생 

#include <iostream>
#include <memory.h>

using namespace std;

int map[510][510];
int dp[510][510]; //y,x에서 0,0까지 가는 경로의 수 반환 
int M,N;
int ans;

int travel(int y, int x)
{
	int arr_i[4] = {0,-1,0,1};
	int arr_j[4] = {-1,0,1,0};
	int high = map[y][x];

	if(y==0 && x==0) //0,0에서 0,0으로 가는 방법은 한 가지. 
	{
	 return dp[y][x] = 1;	
	}

	if(dp[y][x] != -1)
	 return dp[y][x];
	else
	 dp[y][x] = 0; //초기 경로의 갯수는 없음 

	for(int k=0;k<4;k++)
	{
		int cur_y = y+arr_i[k];
		int cur_x = x+arr_j[k];
		if(cur_y < 0 || cur_x < 0 || cur_y > M-1 || cur_x > N-1)
		 continue;
		if(high < map[cur_y][cur_x])//좌/상/우/하 방향 각각 현재 위치보다 높은 곳으로 가는 지 확인 
		{
			dp[y][x] = dp[y][x] + travel(cur_y,cur_x); //핵심// 내 위치에서 0,0으로 가는 경우의 수는 각 좌/상/우/하 각 방향으로 갈 수 있는 방법의 수를 모두 더한 것임**
		}
	}	
	return dp[y][x];
}


int main(void)
{
	cin >> M >> N;
	for(int i=0;i<M;i++)
	{
	 for(int j=0;j<N;j++)
	 {
		int h=0;
		scanf("%d",&h);
		map[i][j] = h;
	 }
	}
	memset(dp,-1,sizeof(dp));

	travel(M-1,N-1);
	cout << dp[M-1][N-1] << endl;
	return 0;
} 
