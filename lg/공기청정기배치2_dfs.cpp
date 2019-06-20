#include <iostream>
#include <algorithm>

using namespace std;

int H;		// 세로 크기
int W;		// 가로 크기
int map[50][50];	//지도
int lvl[50][50];	//지도
int room_cnt[2501]; //각 방번호별 갯수 확인용

int roomno = 0;

struct ANS{
	int count;	// room 개수
	int area;		// 가장 넓은 room 넓이
};

void InputData(){
	int i, j;
	cin >> H;
	cin >> W;
	for(i=0 ; i<H ; i++){
		for(j=0 ; j<W ; j++){
			cin >> map[i][j];
		}
	}
}

void dfs(int y, int x, int rno) //y,x 위치 rno 부터 방탐색. 
{
	int arri[4] = {0,-1,0,1};//좌/상/우/하 탐색 
	int arrj[4] = {-1,0,1,0};
	
	//printf("dfs %d %d\n",y,x);
 
	lvl[y][x] = rno;
	room_cnt[rno]++;
	
	for(int k=0;k<4;k++)
	{
		int cur_i = y+arri[k];
		int cur_j = x+arrj[k];
		if(cur_i < 0 || cur_j < 0 || cur_i > H-1 || cur_j > W-1)
			continue;
		if(lvl[cur_i][cur_j] != 0)
			continue;
		if(k==0 && (map[y][x] & 0x1) == 0) //벽이 없으면 탐색 
			dfs(cur_i,cur_j,rno);
		if(k==1 && (map[y][x] & 0x2) == 0)
			dfs(cur_i,cur_j,rno);
		if(k==2 && (map[y][x] & 0x4) == 0)
			dfs(cur_i,cur_j,rno);
		if(k==3 && (map[y][x] & 0x8) == 0)
			dfs(cur_i,cur_j,rno);		
	}
	return;	
}

int main(){
	ANS ans = {0, 0};

	InputData();			//	입력 함수

	dfs(0,0,++roomno);
	
	#if 1
	for(int i=0;i<H;i++) //탐색되지 않은 방 찾아서 다시 탐색 
	{
		for(int j=0;j<W;j++)
		{
			if(lvl[i][j] == 0)
			 dfs(i,j,++roomno);
		}
	}
	#endif
		
	ans.count = roomno;
	ans.area = *max_element(room_cnt,room_cnt+2501);
	
	cout << ans.count << endl;	//	정답 출력
	cout << ans.area << endl;		//	정답 출력
	return 0;
}

